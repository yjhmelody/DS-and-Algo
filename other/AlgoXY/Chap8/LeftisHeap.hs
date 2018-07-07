module LeftisHeap where

import Test.QuickCheck
import qualified Data.List as L

data LHeap a = Empty
            | Node Int a (LHeap a) (LHeap a) -- Rank key left right
            deriving (Eq, Show)

rank :: LHeap a -> Int
rank Empty = 0
rank (Node r _ _ _) = r

makeNode :: a -> LHeap a -> LHeap a -> LHeap a
makeNode k a b = if rank a < rank b 
                then Node (rank a + 1) k b a
                else Node (rank b + 1) k a b

merge :: (Ord a ) => LHeap a -> LHeap a -> LHeap a
merge Empty h = h
merge h Empty = h
merge h1@(Node _ x l r) h2@(Node _ y l' r') =
    if x < y 
        then makeNode x l (merge r h2)
        else makeNode y l' (merge h1 r')

findMin :: (Ord a) => LHeap a -> a
findMin (Node _ x _ _) = x

deleteMin :: (Ord a) => LHeap a -> LHeap a
deleteMin (Node _ _ l r) = merge l r

fromList :: (Ord a) => [a] -> LHeap a
fromList = foldl insert Empty

insert :: (Ord a ) => LHeap a -> a -> LHeap a
insert h x = merge h (Node 1 x Empty Empty)

heapSort :: (Ord a) => [a] -> [a]
heapSort = hsort . fromList 
    where 
        hsort Empty = []
        hsort h = (findMin h) : (hsort $ deleteMin h) 