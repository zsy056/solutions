DIGITS = [['M', 1000], ['D', 500], ['C', 100], ['L', 50], ['X', 10], ['V', 5], ['I', 1]]

# @param {String} s
# @return {Integer}
def roman_to_int(s)
  return 0 if s.empty?
  left, match, right = partition s  
  match.size * (DIGITS.select {|x| x[0] == match[0]})[0][1] - roman_to_int(left) + roman_to_int(right)
end

def partition(s)
  prev2 = ''
  match = ''
  remain = ''
  DIGITS.each do |digit|
    prev, match, remain = *s.rpartition(digit[0])
    next if match.empty?
    prev.split('').reverse_each do |c|
      if c == match[0]
        match += c
      else
        prev2 = c + prev2
      end
    end
    break
  end
  [prev2, match, remain]
end
