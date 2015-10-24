require 'set'

# @param {String} s
# @return {Integer}
def calculate(s)
  tokens = tokenize s
  stack = []  
  tokens.each do |token|
    if token == ')'
      tmp = []
      while stack[-1] != '('
        tmp.push stack.pop
      end
      stack.pop
      stack.push caculate_basic tmp.reverse
    else
      stack.push token
    end
  end
  caculate_basic stack
end

def caculate_basic(tokens)
  res = tokens[0]
  i = 1
  while i < tokens.size
    if tokens[i] == '+'
      res += tokens[i+1]
    else
      res -= tokens[i+1]
    end
    i += 2
  end
  res
end


SYMS = Set.new ['+', '-', '(', ')']


def tokenize(s)
  tmp = ''
  s = s.split.join ''
  toks = s.chars.inject([]) do |tokens, c|
    if SYMS.include? c
      tokens.push tmp.to_i unless tmp.empty?
      tmp = ''
      tokens.push c
    else
      tmp += c
    end
    tokens
  end
  toks.push tmp.to_i unless tmp.empty?
  toks
end
