# @param {Integer} x
# @return {Boolean}
def is_palindrome(x)
  return false if x < 0
  reversed = 0  
  ori = x
  while x > 0
    reversed = reversed * 10 + x % 10
    x /= 10
  end
  reversed == ori
end
