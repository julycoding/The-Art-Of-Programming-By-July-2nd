#!/usr/bin/env ruby
# -*- coding: UTF-8 -*-

def swap(s, i, j)
  s[i], s[j] = s[j], s[i]
end

def left_shift_one(s, i, j)
  t = s[i]
  (i...(j - 1)).each{|k| s[k]  = s[k+1] }
  s[j - 1] = t
end

def simple_shift(s, m)
  m = m % s.length if s.length <= m
  right = s.length - m
  s[0...right], s[right..-1] = s[m..-1], s[0...m]
end

def left_shift(s, m)
  m %= s.length
  (0...m).each{ left_shift_one(s, 0, s.length)}
end

def invert(s, _start, _end)
  (0...(_end - _start + 1) / 2).each{|k| s[_start + k ], s[_end - k] = s[_end - k], s[_start + k]}
end


def invert_solution(s, m)
  len = s.length
  invert(s, 0, m - 1)
  invert(s, m, len - 1)
  invert(s, 0, len - 1)
end

if __FILE__== $0
  a1 = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i']
  a2 = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
  a3 = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
  point = 3
  a0_1 = a1.clone
  a0_2 = a2.clone
  a0_3 = a3.clone
  simple_shift(a0_1, point)
  simple_shift(a0_2, point)
  simple_shift(a0_3, point)
  p 'simple_shift:', a0_1, a0_2, a0_3
  puts
  
  a1_1 = a1.clone
  a1_2 = a2.clone
  a1_3 = a3.clone
  left_shift(a1_1, point)
  left_shift(a1_2, point)
  left_shift(a1_3, point)
  p 'left_shift:', a1_1, a1_2, a1_3
  puts

  a2_1 = a1.clone
  a2_2 = a2.clone
  a2_3 = a3.clone
  invert_solution(a2_1, point)
  invert_solution(a2_2, point)
  invert_solution(a2_3, point)
  p 'invert_solution:', a2_1, a2_2, a2_3
  puts

end

