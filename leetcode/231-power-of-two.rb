# @param {Integer} n
# @return {Boolean}
def is_power_of_two(n)
  n != 0 and (n - 1) & n == 0  
end
