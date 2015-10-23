# @param {String} s
# @return {Integer}
def calculate(s)
  s = s.split.join
  tokens = to_tokens s
  return 0 if tokens.empty?
  last = tokens[0]
  res = tokens[0]
  i = 1
  while i < tokens.size
    if tokens[i] == '+'
      res += tokens[i+1]
      last = tokens[i+1]
    elsif tokens[i] == '-'
      res -= tokens[i+1]
      last = -tokens[i+1]
    elsif tokens[i] == '*'
      res += last * tokens[i+1] - last
      last = last * tokens[i+1]
    elsif tokens[i] == '/'
      res += (last / tokens[i+1].to_f).to_i - last
      last = (last / tokens[i+1].to_f).to_i
    end
    i += 2
  end
  res
end


def to_tokens(s)
  tmp = ''
  res = []
  s.each_char do |c|
    if c == '+' || c == '-' || c == '*' || c == '/'
      res.push tmp.to_i
      tmp = ''
      res.push c
    else
      tmp += c
    end
  end
  res.push tmp.to_i
  res
end
