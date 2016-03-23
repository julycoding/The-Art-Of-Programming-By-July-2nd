#!/usr/bin/env ruby
# -*- coding: UTF-8 -*-
require 'benchmark'

class Array
  def find_01(sum)
    new_arr = {}
    self.each{|item| new_arr[item] = 0}
    self.each_with_index{|item, index|
      return [item, sum - item, index] if new_arr.include? (sum - item)
    }
    nil
  end
  
  #This is better one
  def find_02(sum)
    self.each_with_index{|item, index|
      return [item, sum - item, index] if self.include?(sum - item)
    }
    nil
  end

  def find_03(sum)
    new_arr = self.map{|i| sum - i}
    self.each_with_index{|item, index|
      return [item, sum - item, index] if new_arr.include?(sum)
    }
    nil
  end
  
  def find_with_sum(sum, min = 1, max = nil)
    a = []
    max = max.nil? || max > self.length ? self.length: max
    (min..max).each{|i|
      combination(i){|b|
        a.push(b) if b.reduce(:+) == sum
      }
    }
    a
  end

  
end


def find_sum_with_two(array, sum)
  print "find_01  ", array.find_01(sum), "\n"
  print "find_02  ", array.find_02(sum), "\n"
  print "find_03  ", array.find_03(sum), "\n"
  
  Benchmark.bm(10) do |x|
    x.report("find_01:") { 10000.times{ array.find_01(sum) } }
    x.report("find_02:") { 10000.times{ array.find_02(sum) } }
    x.report("find_03:") { 10000.times{ array.find_03(sum) } }
  end
end


def minimum_differential(a, b)
  return nil  if a.length != b.length
  diff = (a.reduce(:+) - b.reduce(:+)) / 2.0
  return a, b if diff == 0
  min_diff, a_index, b_index = diff.abs , -1, -1
  
  a.each_with_index{|a_item, ai|
    b.each_with_index{|b_item, bi|
      _diff = (a_item - b_item - diff).abs
      if(_diff < min_diff)
        min_diff, a_index, b_index = _diff, ai, bi
      end
    }
  }
  if(a_index != -1 && b_index != -1)
    a[a_index], b[b_index] = b[b_index], a[a_index]
    minimum_differential(a, b)
  end
  return a, b
end


if __FILE__ == $0
  
  find_sum_with_two([1, 2, 4, 5, 11, 15], 15)
  find_sum_with_two([1, 2, 19, 20,30, 28, 27, 20, 3, 8, 9, 12, 4, 5, 11, 15], 33)
  
  p [1, 2, 2, 19, 20,30, 28, 27, 20,3, 8, 9, 12, 4, 5, 11, 15].find_with_sum(4, 2, 2)
  
  a, b = [100, 99, 98, 1, 2, 3], [1,2, 3, 4, 5, 40]
  a, b = minimum_differential(a, b)
  p a, b
   
  
end