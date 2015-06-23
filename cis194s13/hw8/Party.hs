{-# OPTIONS_GHC -fno-warn-orphans #-}

module Party where 

import Data.Tree
import Data.List

import Employee 

glCons :: Employee -> GuestList -> GuestList 
glCons employee (GL es fun) = GL (employee : es) (fun + empFun employee)

instance Monoid GuestList where 
  mempty = GL [] 0
  mappend (GL es1 fun1) (GL es2 fun2) = GL (es1 ++ es2) (fun1 + fun2)

moreFun :: GuestList -> GuestList -> GuestList 
moreFun = max 

treeFold :: (a -> [b] -> b) -> Tree a -> b
treeFold f tree = f (rootLabel tree) (map (treeFold f) (subForest tree))

nextLevel :: Employee -> [(GuestList, GuestList)] 
                      -> (GuestList, GuestList)
nextLevel boss [] = (glCons boss mempty, mempty) 
nextLevel boss xs = (glCons boss withoutList, withList)
  where withList    = mconcat $ map fst xs 
        withoutList = mconcat $ map snd xs 

maxFun :: Tree Employee -> GuestList 
maxFun = uncurry moreFun . treeFold nextLevel 

firstName :: Employee -> String
firstName = head . words . empName

instance Ord Employee where 
  compare emp1 emp2 = compare (firstName emp1) (firstName emp2)

formatGL :: GuestList -> String 
formatGL (GL es fun) = "Total fun: " ++ show fun ++ "\n" ++ guestList 
  where guestList = unlines $ map empName $ sort es 
