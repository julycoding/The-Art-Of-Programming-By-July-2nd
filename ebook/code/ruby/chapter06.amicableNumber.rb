#!/usr/bin/env ruby
# -*- coding: UTF-8 -*-

def amicable_number max
  half = max / 2 
  sum = Array.new(max){1}
  (2...half).each do|i|
    (i + i).step(max + 1, i)do|j|
      sum[j] += i unless sum[j].nil?
    end
  end
  ans = []
  sum.each_with_index do | s, i|
   ans.push([i, s]) if s > i && s <= max && sum[s] == i
  end 
  ans
end



if __FILE__ == $0
  amicable_number( 500000 ).each{|e|
    p "%d %d" % e
  }
end
