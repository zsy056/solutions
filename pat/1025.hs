-- TLE on last case
import qualified Data.List as List

merge :: (Ord a) => [a] -> [a] -> [a]
merge [] [] = []
merge ox@(x:xs) [] = ox
merge [] ox@(x:xs) = ox
merge ox@(x:xs) oy@(y:ys)
    | x < y  = x : merge xs oy
    | x > y  = y : merge ox ys
    | x == y = x : y : merge xs ys 

putAll :: (Show a) => [a] -> IO ()
putAll [] = return ()
putAll (x:xs) = do putStrLn $ show x
                   putAll xs

getNumCases :: IO Int
getNumCases = do numCasesStr <- getLine
                 return $ read numCasesStr 

getLocalLists :: Int -> IO [[Student]]
getLocalLists a = doGetLocalLists a 1 

doGetLocalLists :: Int -> Int -> IO [[Student]]
doGetLocalLists a b
    | a < b     = return []
    | otherwise = do numStudents <- getNumCases
                     students <- getStudents numStudents b
                     otherLocations <- doGetLocalLists a (b + 1)
                     return $ students : otherLocations 

getStudents :: Int -> Int -> IO [Student]
getStudents 0 _ = return []
getStudents x locationNum = do line <- getLine
                               let ws = words line
                               students <- getStudents (x - 1) locationNum 
                               return $ 
                                    (Student (ws !! 0) (read $ ws !! 1) 
                                     locationNum 0 0)
                                    : students  

data Student = Student { regNum :: String,
                         score :: Int,
                         locationNum :: Int,
                         localRank :: Int,
                         finalRank :: Int  }

instance Eq Student where
    (Student a _ _ _ _) == (Student b _ _ _ _) = a == b

instance Ord Student where
    compare (Student regNum1 score1 _ _ _) (Student regNum2 score2 _ _ _)
        = compare (score2, regNum1) (score1, regNum2)

instance Show Student where
    show (Student regNum score locationNum localRank finalRank)
        = List.intercalate " " [regNum, show finalRank, show locationNum, show localRank]

localStudent :: (String, Int) -> Student
localStudent (regNum, score) = Student regNum score 0 0 0

updateLocalRank :: Student -> Int -> Student
updateLocalRank stu rank = stu { localRank = rank }

updateFinalRank :: Student -> Int -> Student
updateFinalRank stu rank = stu { finalRank = rank }

assignRank :: (Student -> Int -> Student) -> [Student] -> ([Student], Int)
assignRank _ [] = ([], 0)
assignRank rankUpdater lst@(s:ss) = doAssignRank lst (score s) rankUpdater 1 0

doAssignRank :: [Student] -> Int -> (Student -> Int -> Student) -> Int -> Int -> ([Student], Int)
doAssignRank [] _ _ rank _ = ([], rank)
doAssignRank (s:ss) lastScore rankUpdater rank same
    | score s == lastScore = (rankUpdater s rank : fst res2, snd res2)
    | otherwise = (rankUpdater s (rank + same) : fst res1, snd res1)
    where res1 = doAssignRank ss (score s) rankUpdater (rank + same) 1
          res2 = doAssignRank ss lastScore rankUpdater rank (same + 1)

globalList :: [[Student]] -> [Student]
globalList localLists 
    = foldl merge [] (map (fst . (assignRank updateLocalRank) . List.sort) localLists)

main = do numCases <- getNumCases  
          locationLists <- getLocalLists numCases 
          let final = assignRank updateFinalRank (globalList locationLists)
          print $ snd final 
          putAll $ fst final 

