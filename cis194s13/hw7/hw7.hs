{-# OPTIONS_GHC -Wall #-}

import Buffer
import Scrabble
import Sized
import JoinList
import JoinListBuffer

(!!?) :: [a] -> Int -> Maybe a
[]     !!? _         = Nothing
_      !!? i | i < 0 = Nothing
(x:_)  !!? 0         = Just x
(_:xs) !!? i         = xs !!? (i-1)

main :: IO()
main = do print $ scoreLine "yay " +++ scoreLine "haskell!"
          print jl
          print $ indexJ 2 jl == (jlToList jl !!? 2)
          print $ jlToList (dropJ 2 jl) == drop 2 (jlToList jl)
          print $ jlToList (takeJ 2 jl) == take 2 (jlToList jl)
            where jl = fromString "aaa\nbbb\nccc\nddd\n" :: JoinList (Score, Size) String
