import qualified Data.Set as Set

main = do
    i <- getInteger 
    if isOK i
        then putStrLn "Yes"
        else putStrLn "No"
    putStrLn $ show $ 2 * i

getInteger :: IO Integer
getInteger = do numStr <- getLine
                return $ read numStr 

isOK :: Integer -> Bool
isOK i = toSet i == toSet (i * 2)

toSet :: Integer -> Set.Set Char
toSet i = Set.fromList $ show i
