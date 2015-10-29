# @param {String} s
# @return {Integer}
def longest_valid_parentheses(s)
  stk = []  
  start = nil
  max_len = 0
  s.each_char.with_index do |c, i|
    if c == '('
      stk.push i
      start = i if start.nil?
    elsif stk.empty?
      start = nil
    else
      idx = stk[-1]
      stk.pop
      b = stk.empty? ? [idx, start].min : stk[-1] + 1
      max_len = [max_len, i - b + 1].max
    end
  end
  max_len
end

