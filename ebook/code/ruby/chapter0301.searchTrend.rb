#!/usr/bin/env ruby
# -*- coding: UTF-8 -*-
require 'benchmark'

def create_hash(input)
  hash = Hash.new(0)
  File.open(input, 'r') do |f|
    f.each_line do |line|
      line.split(' ').each do |w|
        hash[w] += 1
      end
    end 
  end
  hash
end

def trend(array, k, v, top = 10, desc = true)
  if (array.length < top - 1)
    array.push([k, v]).sort! do |a, b|
        a[1] <=> b[1]
    end
    return array
  end 
  return array if( v < array[0][1] && desc  || v > array[-1][1] && !desc)
  array[desc ? 0 : -1] = [k, v]
  array.sort! do |a, b|
    a[1] <=> b[1]
  end
end

# input, the file
# top
# desc, true means hot first, false means low first.
def search_trend(input, top = 10, desc = true)
  hash = create_hash(input)
  array = []
  hash.each{|k,v|
    trend(array, k, v, top, desc)
  }
  array
end

if __FILE__ == $0
  format = "%s (%d)"
  # ARGV[0] the file
  search_trend(ARGV[0]).each{|item|
    p format % item
  }
end