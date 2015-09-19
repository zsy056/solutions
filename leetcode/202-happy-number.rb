require 'set'

$cache = Set.new
ZERO_ORD = '0'.ord

# @param {Integer} n
# @return {Boolean}
def is_happy(n)
  $cache = Set.new
  _is_happy n
end


def _is_happy(n)
  return false if $cache.include? n
  res = n.to_s.split('').inject(0) do |sum, x|
    xord = x.ord - ZERO_ORD
    sum + xord * xord
  end
  if res == 1
    true
  else
    $cache.add n
    _is_happy res
  end
end
