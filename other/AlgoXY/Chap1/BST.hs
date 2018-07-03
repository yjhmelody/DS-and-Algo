module BST where

import Test.QuickCheck
import qualified Data.List as L
import Prelude hiding(lookup, min, max)

data Tree a = Empty
            | Node (Tree a) a (Tree a) deriving (Show, Eq)

leaf :: a -> Tree a
leaf a = Node Empty a Empty

left :: Tree a -> Tree a
left (Node l _ _) = l
left _ = Empty

right :: Tree a -> Tree a
right (Node _ _ r) = r
right _ = Empty

key :: Tree a -> Maybe a
key (Node _ k _) = Just k
key _ = Nothing

isEmpty :: Tree a -> Bool
isEmpty Empty = True
isEmpty _ = False

-- 前序遍历映射
mapT :: (a -> b) -> Tree a -> Tree b
mapT _ Empty = Empty
mapT f (Node l x r) = Node (mapT f l) (f x) (mapT f r)

-- 查找值
lookup :: (Ord a) => Tree a -> a -> Tree a
lookup Empty _ = Empty
lookup t@(Node l k r) x | k == x = t
                        | x < k = lookup l x
                        | otherwise = lookup r x

-- 查找最小值
min :: Tree a -> a
min (Node Empty x _) = x
min (Node l _ _) = min l

-- 查找最大值
max :: Tree a -> a
max (Node _ x Empty) = x
max (Node _ _ r) = max r

insert :: (Ord a) => Tree a -> a -> Tree a
insert Empty k = Node Empty k Empty
insert (Node l x r) k   | k < x = Node (insert l k) x r
                        | otherwise = Node l x (insert r k)

-- 如果 x 只有一个孩子，则删除 x
-- 如果 x 有 两个孩子，用右子树最小值替换
delete :: (Ord a) => Tree a -> a -> Tree a
delete Empty _ = Empty
delete (Node l x r) k   | k < x = (Node (delete l k) x r)
                        | k > x = (Node l k (delete r x))
                        -- k == x
                        | isEmpty l = r
                        | isEmpty r = l
                        | otherwise = (Node l x' (delete r x'))
                        where x' = min r



-- Traverse a part of tree inside a range [a, b]
mapR :: (Ord a) => (a -> b) -> a -> a -> Tree a -> Tree b
mapR f a b tree = map' tree
    where
        map' Empty = Empty
        map' (Node l k r)   | k < a = map' r
                            | k >= a && k <= b = Node (map' l) (f k) (map' r)
                            | k > b = map' l

toList :: (Ord a) => Tree a -> [a]
toList Empty = []
toList (Node l x r) = toList l ++ [x] ++ toList r 

fromList :: (Ord a) => [a] -> Tree a
fromList = foldl insert Empty

-- Node (Node Empty 1 Empty) 2 (Node Empty 3 Empty)


-- test code
prop_build :: (Show a, Ord a) => [a] -> Bool
prop_build xs = L.sort xs == (toList $ fromList xs)

prop_map :: (Ord a) => [a] -> Bool
prop_map xs = mapT id (fromList xs) == fromList xs

prop_lookup :: (Ord a) => [a] -> a -> Bool
prop_lookup xs x = f $ key $ lookup (fromList xs) x 
    where
        f Nothing  = not $ elem x xs
        f (Just y) = x == y

prop_min :: (Ord a, Num a) => [a] -> Property
prop_min xs = not (null xs) ==> minimum xs == min (fromList xs)

prop_max :: (Ord a, Num a) => [a] -> Property
prop_max xs = not (null xs) ==> maximum xs == max (fromList xs)

prop_del :: (Ord a, Num a) => [a] -> a -> Bool
prop_del xs x = L.sort (L.delete x xs) == toList (delete (fromList xs) x)

prop_mapR :: (Ord a, Num a) =>[a] -> a -> a -> Bool
prop_mapR xs a b = filter (\x-> a<= x && x <=b) (L.sort xs) ==
                   toList (mapR id a b (fromList xs))

testAll = do
    quickCheck (prop_build :: [Int] -> Bool)
    quickCheck (prop_map :: [Int] -> Bool)
    quickCheck (prop_lookup :: [Int] -> Int -> Bool)
    quickCheck (prop_min :: [Int] -> Property)
    quickCheck (prop_max :: [Int] -> Property)
    quickCheck (prop_del :: [Int] -> Int -> Bool)
    quickCheck (prop_mapR :: [Int] -> Int -> Int -> Bool)