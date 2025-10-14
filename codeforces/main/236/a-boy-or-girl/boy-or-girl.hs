-- #343620711 	Oct/14/2025 02:42UTC+2 	trintler 	236A - Boy or Girl 	Haskell 	Accepted 	154 ms 	0 KB

import Data.List (nub)

main :: IO ()
main = do
    username <- getLine
    let distinctCount = length $ nub username
    if even distinctCount
        then putStrLn "CHAT WITH HER!"
        else putStrLn "IGNORE HIM!"
