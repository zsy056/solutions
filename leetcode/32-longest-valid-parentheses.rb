# @param {String} s
# @return {Integer}
def longest_valid_parentheses(s)
  stk = []  
  counter = 0
  max_len = 0
  s.each_char do |c|
    if c == '('
      stk.push c
    elsif c == ')'
      counter = 0
      while (not stk.empty?) and stk[-1] != '('
        counter += stk[-1]
        stk.pop
      end
      if stk.empty?
        max_len = [max_len, counter].max
      else
        stk.pop
        stk.push counter + 2
      end
    end
  end
  counter = 0
  stk.each do |i|
    if i == '('
      counter = 0
    else
      counter += i
    end
    max_len = [max_len, counter].max
  end
  max_len
end
