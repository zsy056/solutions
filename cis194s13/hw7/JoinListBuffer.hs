{-# LANGUAGE FlexibleInstances, TypeSynonymInstances #-}

module JoinListBuffer where 

import Buffer 
import Scrabble
import Sized
import JoinList 

instance Buffer (JoinList (Score, Size) String) where 
  toString Empty          = ""
  toString (Single _ a)   = a 
  toString (Append _ a b) = toString a ++ toString b
  fromString = fromLines . lines 
    where fromLines []  = Empty 
          fromLines [l] = Single (scoreString l, Size 1) l
          fromLines xs  = fromLines (take halfLines xs) +++ fromLines (drop halfLines xs)
            where halfLines = length xs `div` 2 
  line              = indexJ
  replaceLine n l b = takeJ n b +++ Single (scoreString l, Size 1) l +++ dropJ (n+1) b
  numLines          = getSize . snd . tag
  value             = fromInteger . getScore . fst . tag 
