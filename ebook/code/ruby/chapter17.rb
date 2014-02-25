#!/usr/bin/env ruby
# -*- coding: UTF-8 -*-

def fibonacci_solution n
  return [0, 1, 2][n] if( n <= 2 )
  fibonacci_solution(n - 1) +  fibonacci_solution( n - 2)
end
 
if __FILE__ == $0
  steps = [1, 2, 3, 4, 5, 6]
  p steps.map{|x|
    [x, fibonacci_solution(x)]
  }

end