-- This file has been generated by specsgen. Do not modify by hand!

module Unison.Target.Minimal.SpecsGen.AlignedPairs (alignedPairs)
       where
import Unison.Target.Minimal.SpecsGen.MinimalInstructionDecl
alignedPairs i ([], []) | i `elem` [Nop] = []
alignedPairs i ([_, _], [_]) | i `elem` [Ld] = []
alignedPairs i ([_], []) | i `elem` [Br] = []
alignedPairs i ([_], [_]) | i `elem` [Load, Move, Store] = []
alignedPairs i ([_, _, _], []) | i `elem` [St] = []
alignedPairs i ([_], [_]) | i `elem` [Li] = []
alignedPairs i ([_, _], []) | i `elem` [Bif] = []
alignedPairs i ([_, _], [_]) | i `elem` [Mul, Sgt, Sub] = []
alignedPairs i ([_], []) | i `elem` [B] = []
alignedPairs _ _ = []

