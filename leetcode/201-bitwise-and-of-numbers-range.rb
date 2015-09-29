# @param {Integer} m
# @param {Integer} n
# @return {Integer}
def range_bitwise_and(m, n)
  base = m & n  
  diff = n - m
  i = 0
  while i < 32
    if diff > (1 << i)
      base &= (0xffffffff ^ (1 << i))
    else
      break
    end
    i += 1
  end
  base
end
