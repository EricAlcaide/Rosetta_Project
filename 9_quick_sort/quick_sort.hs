quicksort :: [Int] -> [Int]
quicksort [] = []
quicksort (x:xs) = (quicksort leftSide) ++ [x] ++ (quicksort rightSide)
  where leftSide = filter (<x) xs
        rightSide = filter (>=x) xs

--
main = do
  putStrLn "Awaiting Integer list like: [1,3,6,42,...]"
  myArray <- getLine
  let toSort = read myArray :: [Int]
  putStrLn "The sorted array is:"
  putStrLn $ show $ quicksort toSort
