#!/usr/bin/env ruby
# -*- coding: UTF-8 -*-

def odd_even(arr)
  return arr.select{|x| x % 2 != 0 } +  arr.select{|x| x % 2 == 0 } 
end

def reorder_odd_even(arr)
  si, ei = 0, arr.length - 1
  while si < ei
    if(arr[si].odd?)
      si += 1; next
    end
    if(arr[ei].even?)
      ei -= 1; next
    end 
    arr[si], arr[ei] = arr[ei], arr[si]
  end
  arr
end

if __FILE__ == $0
  test_cases = [ [2, 1, 3, 4, 6, 5, 7] ]
  test_cases.each{|tc|
    p odd_even(tc), reorder_odd_even(tc)
  }
  
end