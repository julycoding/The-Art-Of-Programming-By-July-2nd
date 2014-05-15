#!/usr/bin/env ruby
# -*- coding: UTF-8 -*-
require 'benchmark'
def quick_sort_01(list)
  return [] if list.empty?
  x, *xs = *list
  less, more = xs.partition{ |item| item < x }
  quick_sort_01(less) + [x] + quick_sort_01(more)
end

#This is better method
def quick_sort_02(a)
  (pivot = a.pop) ? quick_sort_02(a.select{|i| i <= pivot}) + [pivot] + quick_sort_02(a.select{|i| i > pivot}) : []
end

def quick_sort_performance(size)
  array = Array.new(size)
  random = Random.new
  max_number = size * 100
  size.times{|i|
    array[i] = random.rand(max_number)
  }
  Benchmark.bm(20) do |x|
    x.report(size.to_s + " of QS 01:")   { quick_sort_01(array) }
    x.report(size.to_s + " of QS 02:")   { quick_sort_02(array) }
  end
end

if __FILE__ == $0

  [100, 1000, 100000, 1000000, 20000, 10000].each{|i|
    quick_sort_performance(i) 
  } 
end