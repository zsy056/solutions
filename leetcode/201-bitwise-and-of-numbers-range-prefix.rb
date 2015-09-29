# @param {Integer} m
# @param {Integer} n
# @return {Integer}
def range_bitwise_and(m, n)
  base = 0
  i = 31
  while i >= 0
    a = m & (1 << i)
    b = n & (1 << i)
    if a == b and a != 0
      base |= a;
    elsif a != b
      break
    end
    i -= 1
  end
  base
end
