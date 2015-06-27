{-# OPTIONS_GHC #-}

import Data.Maybe

import AParser
import SExpr

main :: IO()
main = do print $ runParser (zeroOrMore (char 'a')) "aab" == Just("aa", "b")
          print $ runParser (zeroOrMore (char 'a')) "aaa" == Just("aaa", "")
          print $ runParser (zeroOrMore (char 'a')) "bb"  == Just("", "bb")
          print $ runParser (oneOrMore  (char 'a')) "aab" == Just("aa", "b")
          print $ isNothing $ runParser (oneOrMore  (char 'a')) "bb" 
          print $ runParser ident "foobar baz" == Just("foobar", " baz")
          print $ runParser ident "foo33fA"    == Just("foo33fA", "")
          print $ isNothing $ runParser ident "2bad"
          print $ isNothing $ runParser ident ""
          print $ runParser spaces "  dd" == Just("  ", "dd")
          print $ runParser spaces "ddd"  == Just("", "ddd")
          print $ runParser parseSExpr "5"
          print $ runParser parseSExpr "foo3"
          print $ runParser parseSExpr "(bar (foo) 3 5 874)"
          print $ runParser parseSExpr "(((lambda x (lambda y (plus x y))) 3) 5)"
          print $ runParser parseSExpr "(   lots of  (  spaces in ) this  ( one ) )"
