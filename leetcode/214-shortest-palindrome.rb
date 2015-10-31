# @param {String} s
# @return {String}
def shortest_palindrome(s)
  return '' if s.empty?
  p = manacher s
  tj = 0
  i = p.size / 2
  #puts p.to_s
  while i >= 0
    if p[i] - i == 0
      tj = (p[i] + i) / 2
      break
    end
    i -= 1
  end
  prefix = s[tj..-1]
  prefix = prefix.nil? ? '' : prefix.reverse!
  prefix.concat s
end


def manacher(s)
  stuffed = '#' * (s.size*2+1)
  s.each_char.with_index { |c, i| stuffed[i*2 + 1] = c }
  res = Array.new stuffed.size, 0
  right = 0
  center = 0
  i = 0
  while i <= stuffed.size / 2
    res[i] = [right - i, res[2*center - i]].min
    while i + res[i] + 1 < stuffed.size and i - res[i] - 1 >= 0 and stuffed[i+res[i]+1] == stuffed[i-res[i]-1]
      res[i] += 1
    end
    if res[i] + i > right
      right = res[i] + i
      center = i
    end
    i += 1
  end
  res
end


#puts shortest_palindrome 'aacecaaa'
#puts shortest_palindrome 'abcd'
#puts shortest_palindrome "abbacd"

