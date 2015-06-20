{-# LANGUAGE FlexibleInstances #-}
{-# OPTIONS_GHC -Wall -fno-warn-missing-methods #-}

fib :: Integer -> Integer 
fib 0 = 0
fib 1 = 1
fib n = fib (n - 1) + fib (n - 2)

fibs1 :: [Integer]
fibs1 = [fib i | i <- [0..]]

fibs2 :: [Integer] 
fibs2 = [fib' i | i <- [0..]]

fib' :: Integer -> Integer 
fib' 0 = 0
fib' 1 = 1
fib' n = a + b
  where (a:b:_) = drop (fromIntegral n - 2) fibs2

data Stream a = Con a (Stream a)

streamToList :: Stream a -> [a]
streamToList (Con a s) = a : streamToList s

instance Show a => Show (Stream a) where 
  show a = show $ take 20 (streamToList a)

streamRepeat :: a -> Stream a 
streamRepeat a = Con a (streamRepeat a)

streamMap :: (a -> b) -> Stream a -> Stream b
streamMap f (Con x xs) = Con (f x) (streamMap f xs)

streamFromSeed :: (a -> a) -> a -> Stream a 
streamFromSeed f seed = Con seed (streamFromSeed f (f seed))

nats :: Stream Integer 
nats = streamFromSeed (+1) 0

ruler :: Stream Integer 
ruler = streamMap (toInteger . rule) fromOne
  where rule x = length $ takeWhile (\y -> (x `mod` y) == 0) (iterate (*2) 2)
        (Con 0 fromOne) = nats

instance Num (Stream Integer) where 
  fromInteger x = Con x (streamRepeat 0)
  negate = streamMap (0 -)
  (+) (Con x xs) (Con y ys) = Con (x+y) (xs + ys)
  (*) (Con a0 a') b@(Con b0 b') = Con (a0 * b0) (a' * b + streamMap (*a0) b')

instance Fractional (Stream Integer) where 
  (/) (Con 0 a') (Con 0 b') = a' / b' 
  (/) (Con a0 a') (Con b0 b') = q 
    where q = Con (a0 `div` b0) (streamMap (`div` b0) (a' - q * b'))

fibs3 :: Stream Integer 
fibs3 = px / (1 - px - px^(2 :: Integer))


px :: Stream Integer 
px = Con 0 (Con 1 (streamRepeat 0))

data Matrix = M2x2 Integer Integer Integer Integer 

instance Num Matrix where 
  (*) (M2x2 a00 a01 a10 a11) (M2x2 b00 b01 b10 b11) = M2x2 (a00*b00 + a01*b10) (a00*b01 + a01*b11) (a10*b00+a11*b10) (a10*b01 + a11*b11)

fib4 :: Integer -> Integer 
fib4 0 = 0
fib4 1 = 1
fib4 n = x00 $ M2x2 1 1 1 0 ^ (n-1)
  where x00 (M2x2 a00 _ _ _) = a00

main :: IO()
main = do print $ fib 35
          print $ take 35 fibs1 
          print $ take 35 fibs2
          print (streamRepeat 42 :: Stream Integer)
          print (streamMap (*2) (streamRepeat 42) :: Stream Integer)
          print nats
          print ruler
          print $ px^(4 :: Integer)
          print $ (1 + px)^(5 :: Integer)
          print $ (px^(2 :: Integer) + px + 3) * (px - 5)
          print $ (px + px) / px
          print fibs3
          print $ take 35 (map fib4 [0..])
