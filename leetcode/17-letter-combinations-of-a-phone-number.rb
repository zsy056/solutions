# @param {String} digits
# @return {String[]}
def letter_combinations(digits)
  syms = digits.each_char.map {|x| x.to_sym}  
  com syms, 0
end


def com(syms, b)
  if syms.size == 0
    []
  elsif b == syms.size - 1
    MAPPING[syms[b]].each_char.map {|x| x}
  else
    current = MAPPING[syms[b]].each_char.map {|x| x}
    ans = []
    current.each do |c|
      tail = com(syms, b+1).map {|x| c + x}
      ans += tail
    end
    ans
  end
end

MAPPING = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
