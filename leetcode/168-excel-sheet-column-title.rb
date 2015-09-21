# @param {Integer} n
# @return {String}
def convert_to_title(n)
  res = ''  
  while n > 0
    n -= 1
    rem = n % 26
    res = ('A'.ord + rem).chr + res
    n /= 26
  end
  res
end
