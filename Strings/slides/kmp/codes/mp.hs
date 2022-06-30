b 0 _  = -1
b j ps = 1 + f pj prev bj_1 ps where
    pj = ps !! (j - 1)
    bj_1 = b (j - 1) ps
    prev = ps !! bj_1
    f a c n ps | n == -1    = -1
               | a == c     = n
               | otherwise  = f a d m ps
               where m = b n ps
                     d = ps !! m 

borders ps = [b j ps | j <- [0..(length ps)]]

main = do
    print $ borders "abaaba"
