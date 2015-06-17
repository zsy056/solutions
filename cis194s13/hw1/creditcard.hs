{-# OPTIONS_GHC -Wall #-}

toDigits :: Integer -> [Integer]
toDigits n
  | n <= 0 = []
  | otherwise = toDigits (n `div` 10) ++ [n `mod` 10]

rev :: [a] -> [a]
rev [] = []
rev (x:xs) = rev xs ++ [x]

toDigitsRev :: Integer->[Integer]
toDigitsRev = rev . toDigits 

doubleEveryOther :: [Integer] -> [Integer]
doubleEveryOther = let doubleFromLeft [] = []
                       doubleFromLeft [a] = [a]
                       doubleFromLeft (a : b : xs) = a : (2*b) : doubleFromLeft xs
                   in rev . doubleFromLeft . rev

sumDigits :: [Integer] -> Integer 
sumDigits x = sum $ x >>= toDigits 

validate :: Integer -> Bool
validate x = (sumDigits (doubleEveryOther $ toDigits x) `mod` 10) == 0


main :: IO()
main = do print (toDigits 1024)
          print (toDigitsRev 1024)
          print (toDigits 0)
          print (toDigits (-1024))
          print (toDigitsRev 0)
          print (toDigitsRev (-1024))
          print (doubleEveryOther [1, 0, 2, 4])
          print (doubleEveryOther [1, 2])
          print (sumDigits [12, 1, 3, 4])
          print (validate 4012888888881881)
          print (validate 4012888888881882)
