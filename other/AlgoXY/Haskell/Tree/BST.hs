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

