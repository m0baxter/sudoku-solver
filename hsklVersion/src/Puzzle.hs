
module Puzzle where

import qualified Data.Set as Set
import qualified Data.Map as Map


data Mark = None | One | Two | Three | Four | Five | Six | Seven | Eight | Nine
             deriving Eq

instance Show Mark where
   show None  = " "
   show One   = "1"
   show Two   = "2"
   show Three = "3"
   show Four  = "4"
   show Five  = "5"
   show Six   = "6"
   show Seven = "7"
   show Eight = "8"
   show Nine  = "9"

data Square = Square Mark (Set.Set Mark)

instance Show Square where
   show (Square m _) = show m

data Puzzle = Puzzle (Map.Map (Int, Int) Square) [(Int, Int)]

instance Show Puzzle where
   show (Puzzle grid _) = 
