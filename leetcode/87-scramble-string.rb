# @param {String} s1
# @param {String} s2
# @return {Boolean}
def is_scramble(s1, s2)
  puts "#{s1}, #{s2}"
  return true if s1 == s2
  return false if s1.nil? or s2.nil?
  return false if s1.chars.sort != s2.chars.sort
  i = 1
  while i < s2.size
    return true if is_scramble(s1[0...i], s2[0...i]) and is_scramble(s1[i..-1], s2[i..-1])
    return true if is_scramble(s1[0...i], s2[s2.size-i..-1]) and is_scramble(s1[i..-1], s2[0...s2.size-i])
    i += 1
  end
  false
end

