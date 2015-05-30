-- MLE on the last case
import Control.Monad
import qualified Data.List as List

data Student = Student { num :: String,
                         name :: String,
                         score :: Int  }

instance Eq Student where
    (Student num1 _ _) == (Student num2 _ _) = num1 == num2

instance Ord Student where
    compare (Student num1 _ _) (Student num2 _ _) = compare num1 num2 

instance Show Student where
    show (Student num name score) = num ++ " " ++ name ++ " " ++ show score

compareByName :: Student -> Student -> Ordering
compareByName s1@(Student _ name1 _) s2@(Student _ name2 _)
    = if nameOrd == EQ then compare s1 s2 else nameOrd
      where nameOrd = compare name1 name2

compareByScore :: Student -> Student -> Ordering
compareByScore s1@(Student _ _ score1) s2@(Student _ _ score2)
    = if scoreOrd == EQ then compare s1 s2 else scoreOrd
      where scoreOrd = compare score1 score2 

main = do fstLine <- getLine
          let lwords = words fstLine  
              (totalStudents, field) = (read (lwords !! 0) :: Int, read (lwords !! 1) :: Int) 
          students <- forM [i | i <- [1..totalStudents]] (\_ -> do
            line <- getLine
            let sWords = words line
            return $ Student (sWords !! 0) (sWords !! 1) (read $ sWords !! 2))
          let comparer = [compare, compareByName, compareByScore]
          mapM_ print (List.sortBy (comparer !! (field-1)) students)
          
