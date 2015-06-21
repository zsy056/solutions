module Scrabble where

import Data.Char
import qualified Data.Map.Lazy as LM

data Score = FromInteger Integer
  deriving (Show)

instance Monoid Score where 
  mempty = FromInteger 0
  mappend (FromInteger a) (FromInteger b) = FromInteger (a + b)

score :: Char -> Score 
score c = doGetScore $ LM.lookup (toLower c) scoreMap
  where scoreList = [('a', 1), ('b', 3), ('c', 3), ('d', 2), ('e', 1),
                     ('f', 4), ('g', 2), ('h', 4), ('i', 1), ('j', 8),
                     ('k', 5), ('l', 1), ('m', 3), ('n', 1), ('o', 1),
                     ('p', 3), ('q', 10), ('r', 1), ('s', 1), ('t', 1),
                     ('u', 1), ('v', 4), ('w', 4), ('x', 8), ('y', 4),
                     ('z', 10)]
        scoreMap = LM.fromList scoreList 
        doGetScore Nothing  = FromInteger 0
        doGetScore (Just x) = FromInteger x

scoreString :: String -> Score 
scoreString = mconcat . map score 

getScore :: Score -> Integer 
getScore (FromInteger x) = x
