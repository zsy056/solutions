#!/usr/bin/env ruby

if __FILE__ == $0
  str = STDIN.readline.strip
  n = str.length
  max_n3 = (n + 2) / 3.0
  n1 = max_n3.to_i
  n3 = n + 2 - 2*n1
  (0..(n1-2)).each do |i|
    puts str[i] + (' ' * (n3-2)) + str[n-1-i]
  end
  puts str[(n1-1)..(n1-2+n3)]
end
