import Data.Char

main = do
    num_cases <- getNumCases 
    cases <- getCases num_cases 
    outputs (map (\[a, b, c] -> (a + b) > c) cases) 1

getNumCases :: IO Int
getNumCases = do num_cases <- getLine
                 return $ read num_cases  

getCases :: Int -> IO [[Integer]]
getCases 0 = return []
getCases a = do line <- getLine
                remain <- getCases (a - 1)
                return $ (map read (words line)) : remain

outputs :: [Bool] -> Int -> IO()
outputs [] _ = return ()
outputs (x:xs) i = 
    do putStrLn $ "Case #" ++ show i ++ ": " ++ map toLower (show x)
       outputs xs (i + 1)
