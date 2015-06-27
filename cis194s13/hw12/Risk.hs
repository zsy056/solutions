{-# LANGUAGE GeneralizedNewtypeDeriving #-}

module Risk where

import Data.List
import Control.Applicative
import Control.Monad
import Control.Monad.Random

------------------------------------------------------------
-- Die values

newtype DieValue = DV { unDV :: Int } 
  deriving (Eq, Ord, Show, Num)

first :: (a -> b) -> (a, c) -> (b, c)
first f (a, c) = (f a, c)

instance Random DieValue where
  random           = first DV . randomR (1,6)
  randomR (low,hi) = first DV . randomR (max 1 (unDV low), min 6 (unDV hi))

die :: Rand StdGen DieValue
die = getRandom

------------------------------------------------------------
-- Risk

type Army = Int

data Battlefield = Battlefield { attackers :: Army, defenders :: Army }
  deriving (Show)

battle :: Battlefield -> Rand StdGen Battlefield 
battle (Battlefield a d) = liftA2 Battlefield aNew dNew
  where aDies = getDies activeA 
        dDies = getDies activeD
        getDies num = fmap (sortBy $ flip compare) (replicateM num die)
        activeA = if a > 4 then 3 else max 0 (a-1)
        activeD = if d > 3 then 2 else max 0 (d-1)
        match = fmap getZipList (liftA2 (<*>) (fmap (ZipList . map (>)) aDies) (fmap ZipList dDies))
        total = min a d
        aDecrease = fmap (sum . map (\x -> if x then 1 else 0)) match
        dDecrease = fmap (total -) aDecrease 
        aNew = fmap (a-) aDecrease 
        dNew = fmap (d-) dDecrease 

invade :: Battlefield -> Rand StdGen Battlefield 
invade b@(Battlefield a d)
  | a < 2 || d == 0 = return b
  | otherwise       = battle b >>= invade

successProb :: Battlefield -> Rand StdGen Double
successProb b = fmap (/ fromIntegral tries) count
  where invades = replicateM tries (invade b)
        count = fmap (foldl countSuccess 0) invades 
        countSuccess res (Battlefield _ d)
          | d == 0    = res + 1
          | otherwise = res
        tries = 1000 :: Int
