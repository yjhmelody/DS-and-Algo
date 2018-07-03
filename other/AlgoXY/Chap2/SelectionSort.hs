module Sort where
    
import Test.QuickCheck
import qualified Data.List as L

insert :: (Ord a) => [a] -> a -> [a]
insert [] x = [x]
insert (y:ys) x = if x < y then x:y:ys else y:insert ys x

insertSort :: (Ord a) => [a] -> [a]
insertSort [] = []
insertSort (x:xs) = insert (insertSort xs) x

insertSort' :: (Ord a) => [a] -> [a]
insertSort' = foldl insert []

prop_sort :: (Ord a, Num a) => [a] -> Bool
prop_sort xs = L.sort xs == insertSort xs

prop_sort' :: (Ord a, Num a) => [a] -> Bool
prop_sort' xs = L.sort xs == insertSort' xs