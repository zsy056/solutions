{-# OPTIONS_GHC -Wall #-}

import Data.Maybe

import AParser



main :: IO()
main = do print $ runParser abParser "abcdef" == Just(('a', 'b'), "cdef")
          print $ isNothing $ runParser abParser "aebcdf"
          print $ runParser abParser_ "abcdef" == Just((), "cdef")
          print $ isNothing $ runParser abParser_ "aebcdf"
          print $ runParser intPair "12 34" == Just([12,34], "")
          print $ runParser aorb "ac" == Just('a', "c")
          print $ runParser aorb "bc" == Just('b', "c")
          print $ isNothing $ runParser aorb "cd"
          print $ runParser intOrUppercase "342abcd" == Just((), "abcd")
          print $ runParser intOrUppercase "XYZ" == Just((), "YZ")
          print $ isNothing $ runParser intOrUppercase "foo"
