#!/usr/bin/env ruby
# -*- coding: UTF-8 -*-

def max_sum(arr)
  max, max_sub, sum, sub = arr[0], [arr[0]], 0, [] 
  arr.each do |x|
    if sum >= 0 
      sum += x; sub.push(x)
    else 
      sum, sub = x, [x]
    end
    max, max_sub = sum, sub.clone if(max < sum)
  end
  [max, max_sub]
end

def max(*ar)
  return ar.max
end

def max_sum_2(arr)
  sum = Array.new(arr.length){0}
  sum[0] = arr[0]
  1.upto(arr.length - 1){|i|
    sum[i] = max( arr[i], sum[i-1] + arr[i]) 
  }
  sum.max
end
 

if __FILE__ == $0
  p max_sum([-1,-2,-3,-4])
  p max_sum([1, -2, 3, 10, -4, 7, 2, -5]) 
  
  p max_sum_2([-1,-2,-3,-4])
  p max_sum_2([1, -2, 3, 10, -4, 7, 2, -5]) 
end
