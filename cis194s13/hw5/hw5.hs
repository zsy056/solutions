{-# OPTIONS_GHC -Wall #-}

import Data.Maybe

import ExprT
import Calc

main :: IO()
main = do print $ eval (Mul (Add (Lit 2) (Lit 3)) (Lit 4)) == 20
          print $ eval (Lit 2)
          print $ isNothing $ evalStr "*1"
          print $ evalStr "(2+3)*4" == Just 20
          print $ mul (add (lit 2) (lit 2)) (lit 4) == Mul (Add (Lit 2) (Lit 2)) (Lit 4)
          print $ testInteger == Just (-7)
          print $ testBool == Just True
          print $ testMM == Just (MinMax 5)
          print $ testSat == Just (Mod7 0)
          print $ stackEval "(2+3)*4" 
          print $ stackEval "(2+3)*"
          print (add (lit 3) (var "x") :: VarExprT)
          print $ withVars [("x", 6)] $ add (lit 3) (var "x")
          print $ withVars [("x", 6)] $ add (lit 3) (var "y")
          print $ withVars [("x", 6), ("y", 3)]
                  $ mul (var "x") (add (var "y") (var "x"))
