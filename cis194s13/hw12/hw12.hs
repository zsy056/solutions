{-# OPTIONS_GHC -Wall #-}

import Control.Monad.Random

import Risk

main :: IO()
main = do bf1 <- evalRandIO $ battle (Battlefield 10 3)
          bf2 <- evalRandIO $ battle (Battlefield 4 4)
          print bf1 
          print bf2
          bf3 <- evalRandIO $ invade (Battlefield 10 3)
          bf4 <- evalRandIO $ invade (Battlefield 3 10)
          print bf3 
          print bf4
          prob1 <- evalRandIO $ successProb (Battlefield 10 3)
          prob2 <- evalRandIO $ successProb (Battlefield 2 10)
          prob3 <- evalRandIO $ successProb (Battlefield 10 10)
          print prob1 
          print prob2 
          print prob3
