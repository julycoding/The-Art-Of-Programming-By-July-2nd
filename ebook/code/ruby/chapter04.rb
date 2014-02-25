#!/usr/bin/env ruby
# -*- coding: UTF-8 -*-
require 'benchmark'
class String
  #find sub string start index
  #String#index
  def o_index(sub)
    return nil if !sub || sub.length > length
    len, slen = self.length,  sub.length
    len.times{|i|
      slen.times{|j|
        break unless self[i+j] == sub[j]
        return i  if j == slen - 1
      }
    }
    return nil
  end
  
  #Find the first letter who's count is count
  #count is 1, return first not-repeat char
  #Ruby 1.9 maintains hash order 
  #For Ruby 1.8 find orderedhash http://rubygems.org/gems/orderedhash
  #find first letter who's count is count
  #This supports UTF-8
  def o_first_count_letter(count = 1)
    hash = Hash.new(0)
    each_char{|c|
      hash[c] += 1
    }
    hash.each{|k,v| return k if v == count}
    return nil
  end
end

class Array
  #Copy to dest
  def copy_to(dest)
    dest[0...(length)] = *self
    dest
  end

  class << self
    #class method copy_to.
    def copy(src, dest)
      src.each_with_index{|item, index|
        dest[index] = item 
      }
    end
  end
end
 

if __FILE__ == $0
  p "kabaccdeff".o_index("fccdeff")
  p "kabaccdeff".o_first_count_letter(2)
end