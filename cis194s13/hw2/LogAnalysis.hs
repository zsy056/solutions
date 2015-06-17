{-# OPTIONS_GHC -Wall #-}

module LogAnalysis where

import Log

parseMessage :: String -> LogMessage
parseMessage = doParseMessage . words
  where doParseMessage ws@("E":rest) = parseError rest ws
        doParseMessage ws@("I":rest) = newMessage Info    rest ws
        doParseMessage ws@("W":rest) = newMessage Warning rest ws
        doParseMessage ws            = Unknown $ unwords ws
        parseError (errorCode:rest) ows =
          case reads errorCode :: [(Int, String)] of
            [(code, "")] -> newMessage (Error code) rest ows 
            _            -> Unknown $ unwords ows
        parseError _ ows                = Unknown $ unwords ows
        newMessage msgType (time:rest) ows = 
          case reads time :: [(Int, String)] of 
            [(timestamp, "")] -> LogMessage msgType timestamp (unwords rest)
            _                 -> Unknown $ unwords ows
        newMessage _ _ ows = Unknown $ unwords ows 


parse :: String -> [LogMessage]
parse = map parseMessage . lines

insert :: LogMessage -> MessageTree -> MessageTree 
insert (Unknown _) tree = tree 
insert newLog      Leaf = Node Leaf newLog Leaf 
insert newLog@(LogMessage _ timeToInsert _) (Node left node@(LogMessage _ time _) right)
  | timeToInsert < time = Node (insert newLog left) node right 
  | otherwise           = Node left node (insert newLog right)
insert _ _              = Leaf 

build :: [LogMessage] -> MessageTree 
build = foldr insert Leaf 

inOrder :: MessageTree -> [LogMessage] 
inOrder Leaf = []
inOrder (Node left mid right) = inOrder left ++ mid : inOrder right

whatWentWrong :: [LogMessage] -> [String] 
whatWentWrong = (map getMessage) . inOrder . build . (filter sever)
  where sever (LogMessage (Error level) _ _) = level >= 50 
        sever _                              = False
        getMessage (LogMessage _ _ msg) = msg 
        getMessage _                    = ""
