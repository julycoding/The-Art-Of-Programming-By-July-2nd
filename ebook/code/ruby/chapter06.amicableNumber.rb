#!/usr/bin/env ruby
# -*- coding: UTF-8 -*-


 

if __FILE__ == $0
  max = 5000000
  half = (max**0.5).to_int
  sum = Array.new(max){1}
  (2...half).each do|i|
    (i + i).step(max + 1, i)do|j|
     sum[j] += i unless sum[j].nil?
    end
  end
  
  
  
  sum.each_with_index do | s, i|
    p "%d %d" % [i, s] if s > i && s <= max && sum[s] == i
  end
end

