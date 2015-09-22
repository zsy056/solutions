$cache = [[''], ['()']]

# @param {Integer} n
# @return {String[]}
def generate_parenthesis(n)
  while $cache.size < n + 1
    to_add = $cache.size
    res = []
    (0...to_add).each do |i|
      left = $cache[i]
      right = $cache[to_add - 1 - i]
      res += left.flat_map {|l| right.map {|r| "(#{l})#{r}"}}
    end
    $cache.push res
  end
  $cache[n]
end
