
import Data.List (nub)

main :: IO ()
main = do
    username <- getLine
    let distinctCount = length $ nub username
    if even distinctCount
        then putStrLn "CHAT WITH HER!"
        else putStrLn "IGNORE HIM!"
