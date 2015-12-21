# @param {String} num
# @return {Boolean}
def is_additive_number(num)
  len = num.size
  (0...len-1).each do |i|
    (i+1...len-1).each do |j|
      a = num[0..i].to_i
      b = num[i+1..j].to_i
      new_end = j+1
      while true
        #puts "#{i}, #{j}, #{a}, #{b}"
        break if new_end >= len
        pl = prefix_len(a+b, num[new_end...len])
        break if pl <= 0
        a, b = b, a + b
        new_end += pl
        break if num[j+1] == '0'
      end
      return true if new_end == len
      break if num[i+1] == '0'
    end
    break if num[0] == '0'
  end
  false
end


def prefix_len(x, num)
  prefix = x.to_s
  if num.start_with? prefix
    prefix.size
  else
    -1
  end
end
