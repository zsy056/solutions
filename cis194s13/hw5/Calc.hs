{-# LANGUAGE TypeSynonymInstances, FlexibleInstances #-}

module Calc where

import qualified Data.Map as M

import ExprT
import Parser
import qualified StackVM as VM

eval :: ExprT -> Integer
eval (Lit x) = x
eval (Add exp1 exp2) = eval exp1 + eval exp2
eval (Mul exp1 exp2) = eval exp1 * eval exp2

evalStr :: String -> Maybe Integer 
evalStr s = fmap eval (parseExp Lit Add Mul s)

class Expr a where
  lit :: Integer -> a
  mul :: a -> a -> a
  add :: a -> a -> a 

class HasVars a where 
  var :: String -> a

data VarExprT = VLit Integer 
              | VAdd VarExprT VarExprT 
              | VMul VarExprT VarExprT 
              | Var String 
  deriving (Show, Eq)

instance HasVars VarExprT where 
  var = Var 

instance Expr VarExprT where 
  lit = VLit 
  mul = VMul 
  add = VAdd 

instance HasVars (M.Map String Integer -> Maybe Integer) where 
  var = M.lookup 

instance Expr (M.Map String Integer -> Maybe Integer) where 
  lit x _ = Just x
  add x y m = do a <- x m
                 b <- y m 
                 return (a + b)
  mul x y m = do a <- x m 
                 b <- y m
                 return (a * b)

withVars :: [(String, Integer)]
            -> (M.Map String Integer -> Maybe Integer)
            -> Maybe Integer
withVars vs expx = expx $ M.fromList vs

instance Expr ExprT where 
  lit = Lit 
  mul = Mul 
  add = Add 

instance Expr Integer where 
  lit = id 
  mul a b = a * b
  add a b = a + b

instance Expr Bool where 
  lit = (> 0)
  add = (||)
  mul = (&&)

newtype MinMax = MinMax Integer deriving (Eq, Show)
newtype Mod7 = Mod7 Integer deriving (Eq, Show)

instance Expr MinMax where 
  lit = MinMax 
  add (MinMax a) (MinMax b) = MinMax $ max a b
  mul (MinMax a) (MinMax b) = MinMax $ min a b

instance Expr Mod7 where 
  lit = Mod7 . (`mod` 7)
  add (Mod7 a) (Mod7 b) = Mod7 $ (a + b) `mod` 7
  mul (Mod7 a) (Mod7 b) = Mod7 $ (a * b) `mod` 7

testExp :: Expr a => Maybe a
testExp = parseExp lit add mul "(3 * -4) + 5"

testInteger :: Maybe Integer
testInteger = testExp 

testBool :: Maybe Bool
testBool = testExp 

testMM :: Maybe MinMax 
testMM = testExp :: Maybe MinMax

testSat :: Maybe Mod7
testSat = testExp :: Maybe Mod7

instance Expr VM.Program where 
  lit x = [VM.PushI x]
  add exp1 exp2 = exp1 ++ exp2 ++ [VM.Add]
  mul exp1 exp2 = exp1 ++ exp2 ++ [VM.Mul]

compile :: String -> Maybe VM.Program 
compile = parseExp lit add mul 

stackEval :: String -> Maybe (Either String VM.StackVal)
stackEval s = fmap VM.stackVM (compile s)
