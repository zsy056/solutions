# @param {Integer} n
# @param {Integer} k
# @return {String}
def get_permutation(n, k)
  _get_perm((1..n).map {|x| x.to_s}, k - 1).join ''  
end


def _get_perm(s, k)
  return [s[0]] if s.size == 1
  remain_cnt = $facts[s.size-1]
  seq = k / remain_cnt
  s[0], s[seq] = s[seq], s[0]
  [s[0], _get_perm(s[1..-1].sort, k % remain_cnt)]
end


$facts = (1..9).inject([1]) {|m, x| m.push m[-1] * x}
