# @param {String} input
# @return {Integer[]}
def diff_ways_to_compute(input)
  tokens = tokenize input  
  get_ways(tokens, 0, tokens.size).map {|x| eval x}
end


def get_ways(tokens, b, e)
  if b == e
    ['']
  elsif e - b <= 3
    ["#{tokens[b...e].join('')}"]
  else
    ans = []
    i = b + 1
    while i < e
      left = get_ways tokens, b, i
      right = get_ways tokens, i+1, e
      res = left.flat_map {|l| right.map {|r| "(#{l})#{tokens[i]}(#{r})"}}
      ans += res
      i += 2
    end
    ans
  end
end


def tokenize(input)
  current = ''
  ans = []
  input.each_char do |c|
    if is_num? c
      current += c
    else
      unless current.empty?
        ans << current
        current = ''
      end
      ans << c
    end
  end
  unless current.empty?
    ans << current
  end
  ans
end

def is_num?(str)
  true if Integer(str) rescue false
end
