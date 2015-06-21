module JoinList where

import Sized
import Scrabble

data JoinList m a = Empty
                  | Single m a
                  | Append m (JoinList m a) (JoinList m a)
  deriving (Eq, Show)

tag :: Monoid m => JoinList m a -> m 
tag Empty = mempty
tag (Single m _) = m
tag (Append m _ _) = m

(+++) :: Monoid m => JoinList m a -> JoinList m a -> JoinList m a 
Empty +++ Empty = Empty 
Empty +++ b     = b
a     +++ Empty = a
a     +++ b     = Append (mappend (tag a) (tag b)) a b

indexJ :: (Sized b, Monoid b) => Int -> JoinList b a -> Maybe a
indexJ _ Empty                  = Nothing 
indexJ s l
  | s >= getSize (size (tag l)) = Nothing 
  | s <  0                      = Nothing 
  | otherwise = getIndexJ l 
    where getIndexJ (Single _ a) = Just a
          getIndexJ (Append _ a b)
            | s >= asize = indexJ (s-asize) b
            | otherwise  = indexJ s a 
              where asize = getSize $ size (tag a)

dropJ :: (Sized b, Monoid b) => Int -> JoinList b a -> JoinList b a
dropJ s l
  | s >= getSize (size (tag l)) = Empty 
  | s <= 0                      = l
  | otherwise                   = doDrop l
    where doDrop (Single _ _) = Empty 
          doDrop (Append _ a b)
            | s > asize = dropJ (s-asize) b
            | otherwise = dropJ s a +++ b
              where asize = getSize $ size (tag a)

takeJ :: (Sized b, Monoid b) => Int -> JoinList b a -> JoinList b a
takeJ s l
  | s >= getSize (size (tag l)) = l
  | s <= 0                      = Empty 
  | otherwise                   = doTake l
    where doTake a@(Single _ _) = a
          doTake (Append _ a b)
            | s > asize = a +++ takeJ (s-asize) b
            | otherwise = takeJ s a 
              where asize = getSize $ size (tag a)

jlToList :: JoinList m a -> [a]
jlToList Empty          = []
jlToList (Single _ a)   = [a]
jlToList (Append _ a b) = jlToList a ++ jlToList b

scoreLine :: String -> JoinList Score String 
scoreLine x = Single (scoreString x) x
