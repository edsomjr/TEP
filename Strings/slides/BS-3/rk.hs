import Data.Char

f :: Char -> Int
f c = (ord c) - (ord 'a') + 1

h :: String -> Int
h s = sum (zipWith (*) fs ps) `mod` q where
    p = 31
    q = 10^9 + 7
    fs = map f s
    ps = map (\x -> p ^ x) $ take (length s) [0..]

rabin_karp :: String -> String -> Int
rabin_karp s p = sum rs where
    n = length s
    m = length p
    hp = h p
    xss = [take m (drop i s) | i <- [0..(n - m)]]
    rs = [fromEnum (h xs == hp && xs == p) | xs <- xss]

main = print $ rabin_karp "abababababab" "aba"
