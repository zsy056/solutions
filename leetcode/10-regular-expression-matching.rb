# @param {String} s
# @param {String} p
# @return {Boolean}
def is_match(s, p)
  tokens = tokenize p
  m, n = s.size, tokens.size
  match = (0..m).map { Array.new n+1, false }
  match[0][0] = true
  (1..n).each { |j| match[0][j] = match[0][j-1] && tokens[j-1][1] }
  (1..m).each do |i|
    (1..n).each do |j|
      cond1 = match[i-1][j] && tokens[j-1][1] && (tokens[j-1][0] == '.' || tokens[j-1][0] == s[i-1])
      cond2 = match[i-1][j-1] && (tokens[j-1][0] == '.' || tokens[j-1][0] == s[i-1])
      cond3 = match[i][j-1] && tokens[j-1][1]
      match[i][j] = cond1 || cond2 || cond3
    end
  end
  match[m][n]
end

def tokenize(p)
  res = []
  p.each_char.with_index do |c, i|
    res.push [c, (i != p.size-1 and p[i+1] == '*')] if c != '*'
  end
  res
end

