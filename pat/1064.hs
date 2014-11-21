{-# LANGUAGE ViewPatterns #-}
import qualified Data.Sequence as Seq
import qualified Data.List as List
import qualified Debug.Trace as Trace

main = do
    num_nodes <- getLine
    nums <- getLine
    putStrLn $ List.intercalate  " " (map show (reorder . List.sort . toIntList $ nums))

toIntList :: (Num a, Read a) => String -> [a]
toIntList a = map read (words a)

reorder :: (Ord a) => [a] -> [a]
reorder [] = []
reorder a = doReOrder (Seq.singleton a) 

doReOrder :: (Ord a) => Seq.Seq [a] -> [a]
doReOrder (Seq.null -> True) = []
doReOrder (Seq.viewl -> [] Seq.:< rem) = []
doReOrder (Seq.viewl -> hd Seq.:< rem)
    = (hd !! firstPart) : doReOrder (rem Seq.|> (take firstPart hd) Seq.|> (drop (firstPart + 1) hd))
    where firstPart = firstPartLen $ length hd

firstPartLen :: Int -> Int
firstPartLen 0 = 0
firstPartLen 1 = 0
firstPartLen totalLen = leftExtra + ((totalLen - extra) `div` 2)
    where h = ceiling $ logBase 2 (fromIntegral $ totalLen + 1)
          extra = totalLen - 2^(h - 1) + 1
          leftExtra = if extra >= 2^(h-2) then 2^(h-2) else extra 
