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

def invert(s, from, to)
  (0...(to - from + 1) / 2).each{|i| s[from + i], s[to - i] = s[to - i], s[from + i]}
end


def invert_solution(s, m)
  len = s.length
  invert(s, 0, m - 1)
  invert(s, m, len - 1)
  invert(s, 0, len - 1)
end

if __FILE__== $0
  a1 = "abcdefghi"
  a2 = "abcdefgh"
  a3 = "abcdefg"
  point = 3
  test_results = [a1, a2, a3].map do |s|
    s = s.dup
	simple_shift s, point
	s
  end

  puts 'simple_shift:', test_results
  puts
  
  test_results = [a1, a2, a3].map do |s|
    s = s.dup
	left_shift s, point
	s
  end
  puts 'left_shift:', test_results
  puts

  test_results = [a1, a2, a3].map do |s|
    s = s.dup
	invert_solution s, point
	s
  end
  puts 'invert_solution:', test_results
  puts

end
