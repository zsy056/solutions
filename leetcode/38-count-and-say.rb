# @param {Integer} n
# @return {String}
def count_and_say(n)
  i = 1
  current = '1'
  while i < n
    current = _count_and_say current
    i += 1
  end
  current
end

def _count_and_say(n)
  result = []
  n.split('').each do |c|
    if result.empty? or result[-1][0] != c
      result.push [c, 1]
    else
      result[-1][1] += 1
    end
  end
  result.inject('') {|s, i| s + i[1].to_s + i[0]}
end
