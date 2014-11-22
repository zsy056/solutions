import qualified Data.List as List

main = do testCase <- getCase
          let answer = getAnswer testCase
          putStrLn $ show $ fst answer
          putStrLn $ show $ snd answer 

getCase :: IO (Integer, Int)
getCase = do line <- getLine
             let ws = words line
             return (read $ ws !! 0, read $ ws !! 1) 

getAnswer :: (Integer, Int) -> (Integer, Int)
getAnswer (result, k) = doGetAnswer result k 0

doGetAnswer :: Integer -> Int -> Int -> (Integer, Int)
doGetAnswer result k n 
    | k == n    = (result, k)
    | isPalindromic = (result, n)
    | otherwise = doGetAnswer reverseI k (n+1) 
    where orginal = show result
          reverse = List.reverse orginal
          isPalindromic = orginal == reverse
          reverseI = result + read reverse
