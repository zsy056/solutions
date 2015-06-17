module Golf where

skips :: [a] -> [[a]] 
skips [] = []
skips xs = [getN xs i | i <- [1..length xs] ]
  where getN [] _ = []
        getN ys i = drop (i-1) (take i ys) ++ getN (drop i ys) i

localMaxima :: [Integer] -> [Integer]
localMaxima []    = []
localMaxima [_]   = []
localMaxima [_,_] = []
localMaxima (x:y:z:rest)
  | (x < y) && (z < y) = y : localMaxima (y:z:rest)
  | otherwise         = localMaxima (y:z:rest)

histogram :: [Integer] -> String 
histogram x = concat hist ++ "==========\n0123456789\n"
  where 
    hist = map ((++"\n") . doGetHist counts) [maxCount, (maxCount-1)..1]
    doGetHist cs tc = map (rightChar tc) cs
    rightChar tc c
      |  c >= tc  = '*'
      | otherwise = ' '
    maxCount = maximum counts
    counts = map count [0..9] 
    count t = length (filter (==t) x)
