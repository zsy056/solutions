# @param {Integer} n
# @return {Integer}
def climb_stairs(n)
  a, b = climb(n)
  b
end

def climb(n)
  return [0, 1] if n == 0
  a, b = climb(n-1)
  [b, a+b]
end
