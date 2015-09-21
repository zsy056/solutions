$cache = {0 => 1, 1 => 1}

# @param {Integer} n
# @return {Integer}
def num_trees(n)
  if $cache.include? n
    $cache[n]
  else
    i = 0
    sum = 0
    while i < n
      sum += num_trees(i) * num_trees(n - 1 - i)
      i += 1
    end
    $cache[n] = sum
    sum
  end
end
