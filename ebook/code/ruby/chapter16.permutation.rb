#!/usr/bin/env ruby
# -*- coding: UTF-8 -*-
def permutation_recursive(ar)
  return [ar] if ar.length == 1
  permutations = []
  ar.each_with_index{|a, i|
    arc = ar.clone; arc.delete_at(i)
    subpermutations = permutation_recursive(arc)
    subpermutations.each{|x|
      permutations.push( [a] + x)
    }
  }
  
  return permutations
end


if __FILE__ == $0
  test_cases = [["A", "B", "C"]]
  test_cases.each{|tc|
    permutations = permutation_recursive(tc)
    p "permutation", permutations, permutations.sort == tc.permutation(tc.length).sort
  }
  


end