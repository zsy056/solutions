-- TLE on last case
import qualified Data.List as List
import qualified Data.Sequence as Seq

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
    compare (Student regNum1 _ _ _ _) (Student regNum2 _ _ _ _)
        = compare regNum1 regNum2

instance Show Student where
    show (Student regNum score locationNum localRank finalRank)
        = List.intercalate " " [regNum, show finalRank, show locationNum, show localRank]

localStudent :: (String, Int) -> Student
localStudent (regNum, score) = Student regNum score 0 0 0

updateLocalRank :: Student -> Int -> Student
updateLocalRank stu rank = stu { localRank = rank }

updateFinalRank :: Student -> Int -> Student
updateFinalRank stu rank = stu { finalRank = rank }

localScores :: [Student] -> Seq.Seq [Student]
localScores ss = doLocalScores ss (Seq.fromList [[] | i <- [0..100]])

doLocalScores :: [Student] -> Seq.Seq [Student] -> Seq.Seq [Student]
doLocalScores [] acc = acc
doLocalScores (s:ss) acc = 
    doLocalScores ss (Seq.update sScore (s:sameScore) acc)
    where sScore = (score s)
          sameScore = Seq.index acc sScore

globalLists :: [Seq.Seq [Student]] -> Seq.Seq [Student]
globalLists ss = doGlobalLists ss (Seq.fromList [[] | i <- [0..100]])

doGlobalLists :: [Seq.Seq [Student]] -> Seq.Seq [Student] -> Seq.Seq [Student]
doGlobalLists [] acc = acc
doGlobalLists (s:ss) acc = doGlobalLists ss (mergeScore s acc)

mergeScore :: Seq.Seq [Student] -> Seq.Seq [Student] -> Seq.Seq [Student]
mergeScore a b = doMergeScore a b b 100

doMergeScore :: Seq.Seq [Student] -> Seq.Seq [Student] -> Seq.Seq [Student] -> Int -> Seq.Seq [Student]
doMergeScore a b acc (-1) = acc
doMergeScore a b acc idx =
    doMergeScore a b (Seq.update idx (as ++ bs) acc) (idx-1)
    where as = Seq.index a idx
          bs = Seq.index b idx 

updateRank :: Seq.Seq [Student] -> (Student -> Int -> Student) -> (Seq.Seq [Student], Int)
updateRank ss updater = foldl (updateRankIter updater) (ss, 1) [100,99..0]

updateRankIter :: (Student -> Int -> Student) -> (Seq.Seq [Student], Int) -> Int -> (Seq.Seq [Student], Int)
updateRankIter updater (ss, currentRank) score =
    (Seq.update score afterUpdate ss, currentRank + sameScore)
    where students = Seq.index ss score
          sameScore = length students
          afterUpdate = doUpdateRank students updater currentRank 

doUpdateRank :: [Student] -> (Student -> Int -> Student) -> Int -> [Student]
doUpdateRank ss updater newRank = map ((flip updater) newRank) ss

outPut :: Seq.Seq [Student] -> IO ()
outPut scores = doOutPut scores 100 

doOutPut :: Seq.Seq [Student] -> Int -> IO ()
doOutPut scores (-1) = return ()
doOutPut scores score = do putAll $ List.sort (Seq.index scores score)
                           doOutPut scores (score-1)

main = do numCases <- getNumCases  
          locationLists <- getLocalLists numCases 
          let locationScores = map (fst . ((flip updateRank) updateLocalRank)) (map localScores locationLists)
          let globalScores = globalLists locationScores   
          let (finalScores, totalStudents) = updateRank globalScores updateFinalRank
          print $ totalStudents - 1 
          outPut finalScores   

