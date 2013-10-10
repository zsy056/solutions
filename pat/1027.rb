#!/usr/bin/env ruby

MAPING = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'A', 'B', 'C']

def to_mars(color)
  ret = String.new
  while color > 0
    ret = MAPING[color % 13].to_s + ret
    color = color / 13
  end
  puts ret.length
  while ret.length < 2
    ret = '0' + ret
  end
  ret
end

if __FILE__ == $0
  colors = STDIN.readline.split(' ').map { |x| to_mars x.to_i }
  puts "##{colors.join ''}"
end
