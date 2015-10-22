# @param {Integer} n
# @return {Integer}
def count_digit_one(n)
  counter = 0
  i = 0
  rem = 0
  while n > 0
    x = n % 10
    counter += get_pn(i) * x
    if x >= 2
      counter += (10 ** i)
    elsif x >= 1
      counter += rem + 1
    end
    rem += (10 ** i) * x
    i += 1
    n /= 10
  end
  counter
end


def get_pn(n)
  while n >= $p.size
    $p.push $p[-1] * 10 + 10 ** ($p.size-1)
  end
  $p[n]
end


$p = [0]

