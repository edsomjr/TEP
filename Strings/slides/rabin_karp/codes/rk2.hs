import Data.Char

p = 31
q = 10^9 + 7

f :: Char -> Int
f c = (ord c) - (ord 'a') + 1

h :: String -> Int
h s = sum (zipWith (*) fs ps) `mod` q where
    fs = map f s
    ps = map (\x -> p ^ x) $ take (length s) [0..]

fastExpMod :: Int -> Int -> Int
fastExpMod _ 0 = 1
fastExpMod a n = (b * fastExpMod (a^2 `mod` q) (n `div` 2)) `mod` q where
    b = if n `mod` 2 == 1 then a else 1

rolling_hash :: String -> Int -> Char -> Int -> [Int]
rolling_hash xs _ _ m | length xs < m = []
rolling_hash (x:xs) prev c m = hs : rolling_hash xs hs x m where
    i = fastExpMod p (q - 2)
    k = fastExpMod p (m - 1)
    d = xs !! (m - 2)
    hs = ((prev - f(c))*i + k*f(d)) `mod` q 

rabin_karp :: String -> String -> Int
rabin_karp s p = length $ filter validate (zip ys [0..]) where
    m = length p
    hp = h p
    hs = h $ take m s 
    ys = hs : rolling_hash (tail s) hs (head s) m
    validate (hb, i) = hb == hp && take m (drop i s) == p

main :: IO ()
main = print $ rabin_karp "ababababababa" "aba"
