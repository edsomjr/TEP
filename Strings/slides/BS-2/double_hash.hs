import Data.Char

f :: Char -> Int
f c = (ord c) - (ord 'a') + 1

hi :: String -> Int -> Int -> Int
hi s p m = sum (zipWith (*) fs ps) `mod` m where
    fs = map f s
    ps = map (\x -> p ^ x) $ take (length s) [0..]

h :: String -> (Int, Int)
h s = (hi s p1 m1, hi s p2 m2) where
    p1 = 31
    m1 = 10^9 + 7
    p2 = 29
    m2 = 10^9 + 9

main :: IO ()
main = do
    s <- getLine
    print $ h s
