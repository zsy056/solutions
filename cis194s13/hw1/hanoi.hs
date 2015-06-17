{-# OPTIONS_GHC -Wall #-}

type Peg  = String
type Move = (Peg, Peg)

hanoiN :: Integer -> [Peg] -> [Move]
hanoiN 0 _ = []
hanoiN 1 (p1:p2:_) = [(p1, p2)]
hanoiN d (p1:p2:p3:ps) = 
  let k = if null ps then d - 1 else d `div` 2
  in hanoiN k (p1:p3:p2:ps) ++ hanoiN (d-k) (p1:p2:ps) ++ hanoiN k (p3:p2:p1:ps)
hanoiN _ _ = []

hanoi :: Integer -> Peg -> Peg -> Peg -> [Move]
hanoi d p1 p2 p3 = hanoiN d [p1, p2, p3]

hanoi4 :: Integer -> Peg -> Peg -> Peg  -> Peg -> [Move]
hanoi4 d p1 p2 p3 p4 = hanoiN d [p1, p4, p2, p3]

main :: IO()
main = do print $ hanoi 2 "a" "b" "c"
          print $ hanoi 5 "a" "b" "c"
          print $ length $ hanoi4 15 "a" "b" "c" "d"
