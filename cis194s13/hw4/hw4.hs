{-# OPTIONS_GHC -Wall #-}

import Data.List

fun1 :: [Integer] -> Integer 
fun1 [] = 1
fun1 (x:xs)
  | even x    = (x - 2) * fun1 xs 
  | otherwise = fun1 xs

fun1' :: [Integer] -> Integer
fun1' = foldr (\x r -> (x-2) * r) 1 . filter even

fun2 :: Integer -> Integer 
fun2 1 = 0
fun2 n | even n    = n + fun2 (n `div` 2)
       | otherwise = fun2 (3 * n + 1)

fun2' :: Integer -> Integer 
fun2' = sum . filter even . takeWhile (/= 0) . iterate getNext 
  where getNext x
          | x == 1    = 0
          | even x    = x `div` 2
          | otherwise = 3 * x + 1

data Tree a = Leaf
            | Node Integer (Tree a) a (Tree a)
  deriving (Show, Eq)

foldTree :: [a] -> Tree a
foldTree = foldr balancedInsert Leaf 

balancedInsert :: a -> Tree a -> Tree a 
balancedInsert x Leaf = Node 0 Leaf x Leaf 
balancedInsert x (Node _ lt v rt)
  | lh <= rh  = Node (max nlh rh + 1) nlt v rt 
  | otherwise = Node (max lh nrh + 1) lt v nrt
  where lh = getHeight lt 
        rh = getHeight rt 
        nlt@(Node nlh _ _ _) = balancedInsert x lt 
        nrt@(Node nrh _ _ _) = balancedInsert x rt

getHeight :: Tree a -> Integer 
getHeight Leaf           = -1
getHeight (Node h _ _ _) = h

validateTree :: Tree a -> Bool 
validateTree Leaf = True 
validateTree (Node h lt _ rt)
  = h == (1 + max (getHeight lt) (getHeight rt)) 
    && validateTree lt && validateTree rt

xor :: [Bool] -> Bool 
xor = odd . length . filter id

map' :: (a -> b) -> [a] -> [b]
map' f = foldr (\x r -> f x : r) []

myFoldl :: (a -> b -> a) -> a -> [b] -> a
myFoldl f base xs = foldr (flip f) base (reverse xs)

cartProd :: [a] -> [b] -> [(a, b)]
cartProd xs ys = [(x, y) | x <- xs, y <- ys]

sieveSundaram :: Integer -> [Integer]
sieveSundaram = map ((+1) . (*2)) . (\x -> [1..x] \\ sieve x)
  where sieve n = filter (<=n)  (map (\(a, b) -> a + b +2*a*b) (filter (uncurry (<=)) (cartProd [1..n] [1..n])))

main :: IO()
main = do print $ fun1  [1, 4, 3]
          print $ fun1' [1, 4, 3]
          print $ fun2  5 
          print $ fun2' 5
          print $ fun2  12
          print $ fun2' 12 
          print $ foldTree "ABCDEFGHIJ"
          print $ validateTree (foldTree "ABCDEFGHIJ")
          print $ xor [False, True, True]
          print $ xor [True, True, True]
          print $ map' Just ([1, 2, 3] :: [Integer])
          print $ myFoldl (\a x -> Node 0 a 0 (Node 0 Leaf x Leaf)) Leaf ([1, 2, 3] :: [Integer])
          print $ foldl (\a x -> Node 0 a 0 (Node 0 Leaf x Leaf)) Leaf ([1, 2, 3] :: [Integer])
          print $ sieveSundaram 100

