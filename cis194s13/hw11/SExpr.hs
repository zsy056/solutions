{- CIS 194 HW 11
   due Monday, 8 April
-}

module SExpr where

import Data.Char

import AParser
import Control.Applicative

------------------------------------------------------------
--  1. Parsing repetitions
------------------------------------------------------------

zeroOrMore :: Parser a -> Parser [a]
zeroOrMore p = oneOrMore p <|> pure []
-- zeroOrMore = many

oneOrMore :: Parser a -> Parser [a]
oneOrMore p = liftA2 (++) (pure <$> p) (zeroOrMore p)
-- oneOrMore = some

------------------------------------------------------------
--  2. Utilities
------------------------------------------------------------

spaces :: Parser String
spaces = zeroOrMore (char ' ')

ident :: Parser String
ident = liftA2 (:) (satisfy isAlpha) (zeroOrMore $ satisfy isAlphaNum)

------------------------------------------------------------
--  3. Parsing S-expressions
------------------------------------------------------------

-- An "identifier" is represented as just a String; however, only
-- those Strings consisting of a letter followed by any number of
-- letters and digits are valid identifiers.
type Ident = String

-- An "atom" is either an integer value or an identifier.
data Atom = N Integer | I Ident
  deriving Show

-- An S-expression is either an atom, or a list of S-expressions.
data SExpr = A Atom
           | Comb [SExpr]
  deriving Show

parseSExpr :: Parser SExpr
parseSExpr = stripSpaces atomParser <|> stripSpaces combList
  where atomParser = A <$> ((N <$> posInt) <|> (I <$> ident))
        combParser = Comb <$> oneOrMore (stripSpaces parseSExpr)
        combList   = char '(' *> combParser <* char ')'
        stripSpaces parser = spaces *> parser <* spaces 
