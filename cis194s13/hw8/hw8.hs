{-# OPTIONS_GHC -Wall #-}

import Party
import Employee

main :: IO()
main = do print $ maxFun testCompany
          print $ maxFun testCompany2
          content <- readFile "company.txt"
          putStrLn $ formatGL (maxFun $ read content)
