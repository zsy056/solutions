# @param {Float} x
# @param {Integer} n
# @return {Float}
def my_pow1(x, n)
  cache = {0 => 1, 1 => x}
  n < 0 ? 1 / _pow(x, -n, cache) : _pow(x, n, cache)
end


def _pow(x, n, cache)
  if cache.include? n
    cache[n]
  else
    mid = n / 2
    cache[n] = _pow(x, n - mid, cache) * _pow(x, mid, cache)
  end
end


def my_pow(x, n)
  if n == 0
    1
  elsif n == 1
    x
  elsif n < 0
    1 / my_pow(x, -n)
  else
    my_pow(x*x, n / 2) * (n & 1 == 0 ? 1 : x)
  end
end
