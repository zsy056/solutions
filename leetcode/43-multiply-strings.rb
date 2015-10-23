# @param {String} num1
# @param {String} num2
# @return {String}
def multiply(num1, num2)
  result = []
  lnum1 = num1.each_char.map {|x| x.to_i}.reverse
  lnum2 = num2.each_char.map {|x| x.to_i}.reverse
  lnum2.each_with_index do |n2, i|
    tmp = mul lnum1, n2
    result = add result, tmp, i
  end
  reduce(result.reverse).join ''
end


def reduce(lnum)
  nzidx = lnum.index {|x| x != 0}
  nzidx.nil? ? lnum[-1..-1] : lnum[nzidx..-1]
end


# lnum1 + (lnum2 << offset)
def add(lnum1, lnum2, offset)
  carry = 0
  result = []
  i = 0
  while i < offset
    if i < lnum1.size
      result.push lnum1[i]
    else
      result.push 0
    end
    i += 1
  end
  while i < lnum1.size and i-offset < lnum2.size
    tmp = lnum1[i] + lnum2[i-offset] + carry
    carry = tmp / 10
    result.push tmp % 10
    i += 1
  end
  while i < lnum1.size
    tmp = lnum1[i] + carry
    carry = tmp / 10
    result.push tmp % 10
    i += 1
  end
  while i-offset < lnum2.size
    tmp = lnum2[i-offset] + carry
    carry = tmp / 10
    result.push tmp % 10
    i += 1
  end
  while carry > 0
    result.push carry % 10
    carry /= 10
  end
  result
end


def mul(lnum, digit)
  result = []
  carry = 0
  lnum.each do |num|
    tmp = digit * num + carry
    carry = tmp / 10
    result.push tmp % 10
  end
  while carry > 0
    result.push carry % 10
    carry /= 10
  end
  result
end
