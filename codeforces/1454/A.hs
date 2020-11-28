import Control.Monad ( replicateM )

main :: IO ()
main = do
    t <- readLn
    putStrLn . unlines . map (\n -> unwords . map show $ n : [1..(n - 1)]) =<< replicateM t (readLn :: IO Int)