#!/usr/bin/env ruby
# -*- coding: UTF-8 -*-

def compare_1(long_string, short_string)
  short_string.each_char{|s| 
    return false unless long_string.include? s
  }
  true
end

def compare_2(long_string, short_string)
  long_string = long_string.chars.sort.join
  short_string = short_string.chars.sort.join
  i,j, n, m = 0, 0, long_string.length, short_string.length
  while i < n && j < m
    i += 1 while long_string[i] < short_string[j] && i < n - 1
    break unless long_string[i] == short_string[j]
    j += 1
  end
  j == m
end

def count_sort(src)
  dst = [""] * src.length
  tmp = [0] * 26
  src.each_char{| c|   tmp[ c.ord - "A".ord ] += 1}
  (1...(tmp.length)).each{ |i| tmp[i] += tmp[i - 1]}
  (src.length - 1).downto(0){ |i|
    c = src[i]
    index = c.ord - "A".ord
    dst[tmp[index] - 1] = c
    tmp[index] -= 1
  }
  dst.join
end


def compare_3(long_string, short_string)
  sorted_long = count_sort(long_string)
  sorted_short = count_sort(short_string)
  pos_long, pos_short = 0, 0
  while pos_short < sorted_short.length && pos_long < sorted_long.length
    while (sorted_long[pos_long] < sorted_short[pos_short] && pos_long < sorted_long.length - 1)
      pos_long += 1
    end
    break if (sorted_long[pos_long] != sorted_short[pos_short])
    pos_short += 1
    
  end

  pos_short == sorted_short.length
end

#这个方法依赖ruby 2.0以上版本, 原因在 String.ord是在ruby 2.0以上才有
#在2.0以前版本可以使用 'A'.unpack('C')[0] 来获得ASCII
def compare_4(long_string, short_string)
  hash_temp , count = [0] * 26, 0
  short_string.each_char{ |c|
    index = c.ord - "A".ord 
    if hash_temp[ index ]  == 0
      hash_temp[index] += 1
      count += 1
    end
  }
  long_string.each_char{ |c|
    index = c.ord - "A".ord 
    if(hash_temp[index] == 1)
      hash_temp[index] -= 1
      count -= 1
    end
  }
  count == 0
end

#这个方法依赖ruby 2.0以上版本, 原因在 String.ord是在ruby 2.0以上才有
#在2.0以前版本可以使用 'A'.unpack('C')[0] 来获得ASCII
def compare_5(long_string, short_string)
  hash_temp = [false] * 26
  short_string.each_char{ |c|
    hash_temp[ c.ord - "A".ord ] = true
  }
  long_string.each_char{ |c|
    hash_temp[ c.ord - "A".ord ] = false
  }
  !hash_temp.include? true
end

#这个方法依赖ruby 2.0以上版本, 原因在 String.ord是在ruby 2.0以上才有
#在2.0以前版本可以使用 'A'.unpack('C')[0] 来获得ASCII
def compare_6(long_string, short_string)
  prime_number = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101]
  product = long_string.chars.inject(1) { |product, n| product * prime_number[ n.ord - "A".ord] }
  short_string.each_char{|c|
    return false unless product % prime_number[ c.ord - "A".ord] == 0
  }
  true
end


#这个是ruby的实现方式
def compare_ruby(long_string, short_string)
  short_string.chars - long_string.chars == []
end



if __FILE__== $0
  long = "ABCDEFGHLMNOPQRSDCGSRQPX"
  short = "DCCCCGSRQPX"
  p compare_1(long, short)
  p compare_2(long, short)
  p compare_3(long, short)
  p compare_4(long, short)
  p compare_5(long, short)
  p compare_6(long, short)
  p compare_ruby(long, short)
  puts 
  
  long = "ABCDEFGHLMNOPQRS"
  short = "DCGSRQPX"
  p compare_1(long, short)
  p compare_2(long, short)
  p compare_3(long, short)
  p compare_4(long, short)
  p compare_5(long, short)
  p compare_6(long, short)
  p compare_ruby(long, short)
end

