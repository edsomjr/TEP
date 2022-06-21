occurrences :: String -> String -> Int
occurrences _ [] = 0
occurrences ps xs = c + occurrences ps (tail xs) where
    m = length ps
    c = if take m xs == ps then 1 else 0
