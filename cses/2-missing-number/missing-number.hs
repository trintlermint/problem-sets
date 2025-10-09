
module Main where

import Data.List (foldl')

main :: IO ()
main = do
  n <- readLn :: IO Int
  numbers <- map read . words <$> getLine :: IO [Int]
  let expectedSum = n * (n + 1) `div` 2
  let actualSum = foldl' (+) 0 numbers
  let missingNumber = expectedSum - actualSum
  
  print missingNumber
