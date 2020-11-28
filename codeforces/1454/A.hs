f :: Int -> IO ()
f 0 = return ()
f t = do
    n <- readLn :: IO Int
    putStrLn . unwords . map show $ n : [1..(n - 1)]
    f (t - 1)

main :: IO ()
main = do
    t <- readLn :: IO Int
    f t