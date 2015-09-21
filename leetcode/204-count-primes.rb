# @param {Integer} n
# @return {Integer}
def count_primes(n)
  return 0 if [0, 1, 2].include? n
  nums = n.times.map {|x| true}  
  nums[0], nums[1] = false, false
  i = 2
  while i * i < n
    while i * i < n and (not nums[i])
      i += 1
    end
    j = i
    while i * j < n
      nums[i * j] = false
      j += 1
    end
    i += 1
  end
  nums.count {|x| x}
end
