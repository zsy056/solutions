# @param {Integer} n
# @return {Integer}
def trailing_zeroes(n)
  m = 0
  while n > 0
    n /= 5
    m += n
  end
  m
end
