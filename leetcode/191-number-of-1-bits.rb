# @param {Integer} n, a positive integer
# @return {Integer}
def hamming_weight(n)
  n.to_s(2).count('1')
end
