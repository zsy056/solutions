# @param {Integer} dividend
# @param {Integer} divisor
# @return {Integer}
def divide(dividend, divisor)
  return 0 if divisor == 0
  return dividend if divisor == 1
  return (dividend == INT_MIN) ? INT_MAX : -dividend if divisor == -1
  is_neg = (divisor > 0) ^ (dividend > 0)
  divisor = divisor.abs
  dividend = dividend.abs
  tdividend = 0
  q = 0
  31.downto(0).each do |i|
    tdividend = (tdividend << 1) | ((dividend >> i) & 1)
    if tdividend >= divisor
      tdividend -= divisor
      q |= (1 << i)
    end
  end
  is_neg ? -q : q
end


INT_MIN = [0x80000000].pack('L').unpack('l')[0]
INT_MAX = 0x7fffffff
