
import Data.Bits
import Control.Monad
import System.IO

bitwiseReverse :: Int -> Int -> Int -> String
bitwiseReverse x y z =

    if (x .&. y) .&. complement z == 0 &&
       (x .&. z) .&. complement y == 0 &&
       (y .&. z) .&. complement x == 0
    
    then "YES"
    else "NO"

main :: IO ()
main = do

    t <- readLn :: IO Int
    replicateM_ t $ do
        [x, y, z] <- map read . words <$> getLine
        putStrLn $ bitwiseReverse x y z
