# @param {Integer} n
# @param {Integer} k
# @return {Integer[][]}
def combine(n, k)
  _com(1, n, k)  
end


def _com(b, n, k)
  return [[]] if k == 0
  res = []
  (b..n-k+1).each do |x|
    res += _com(x+1, n, k-1).map {|a| a.unshift x}
  end
  res
end
