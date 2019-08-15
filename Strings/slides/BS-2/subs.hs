import Data.Char
import Data.Set

p = 31
q = 10^9 + 7

f :: Char -> Int
f c = (ord c) - (ord 'a') + 1

h :: String -> Int
h s = sum (zipWith (*) fs ps) `mod` q where
    fs = Prelude.map f s
    ps = Prelude.map (\x -> p ^ x) $ take (length s) [0..]

prefixes :: String -> [Int]
prefixes s = [h $ take k s | k <- [1..n]] where n = length s

fastExpMod :: Int -> Int -> Int
fastExpMod _ 0 = 1
fastExpMod a n = (b * fastExpMod (a^2 `mod` q) (n `div` 2)) `mod` q where
    b = if n `mod` 2 == 1 then a else 1

inverses :: Int -> [Int]
inverses n = [fastExpMod (fastExpMod p i) (q - 2) | i <- [0..(n-1)]]

hsubs i j ps is
    | i == 0 = ps !! j
    | otherwise = (ps !! j - ps !! (i - 1)) * is !! i `mod` q 

unique_substrings s = length us where
    n = length s
    xs = [(i, j) | i <- [0..(n-1)], j <- [i..(n-1)]] 
    ps = prefixes s
    is = inverses n
    hs = [hsubs i j ps is | (i, j) <- xs]
    us = fromList hs        -- us :: Data.Set

main = do
    print $ unique_substrings "tep"
    print $ unique_substrings "banana"
    print $ unique_substrings "aaaaa"
