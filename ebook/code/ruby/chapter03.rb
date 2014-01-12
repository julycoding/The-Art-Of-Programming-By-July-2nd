#!/usr/bin/env ruby
# -*- coding: UTF-8 -*-

def top_minimum(list, k)
  h = list[0...k]
  list[k..-1].each{|v|
    h.each_index{|i|
      if h[i] > v
        h[i] = v; break
      end
    }
  }
  h
end

if __FILE__== $0
  list = [ 9, 8, 6, 4, 1, 2, 3 ]
  p top_minimum(list, 3)
end

