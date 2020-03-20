solve n | n == 0    = 1
        | otherwise = xs !! (n `mod` 4)
        where xs = [6, 8, 4, 2]

main = do
    n <- readLn :: IO Int
    print $ solve n 
