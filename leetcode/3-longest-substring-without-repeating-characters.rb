require 'set'

# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
  i = 0
  j = 0
  current = Set.new
  max_len = 0
  while j < s.size
    if current.include? s[j]
      while i < s.size and s[i] != s[j]
        current.delete s[i]
        i += 1
      end
      i += 1
    else
      current.add s[j]
    end
    j += 1
    max_len = [max_len, j - i].max
  end
  max_len
end
