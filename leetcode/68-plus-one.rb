# @param {Integer[]} digits
# @return {Integer[]}
def plus_one(digits)
  carry = 1
  idx = digits.size - 1
  digits.reverse_each do |d|
    res = d + carry
    if res >= 10
      carry = 1
      digits[idx] = res % 10
    else
      carry = 0
      digits[idx] = res
    end
    idx -= 1
  end
  if carry == 1
    digits.unshift 1
  end
  digits
end
