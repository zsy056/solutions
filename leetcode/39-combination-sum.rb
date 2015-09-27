# @param {Integer[]} candidates
# @param {Integer} target
# @return {Integer[][]}
def combination_sum(candidates, target)
  candidates = candidates.sort  
  _combination candidates, target, 0
end


def _combination(candidates, target, b)
  if target == 0
    [[]]
  elsif b >= candidates.size
    []
  else
    i = b
    ans = []
    while i < candidates.size and target >= candidates[i]
      c = 1
      while target >= candidates[i] * c
        tails = _combination(candidates, target - candidates[i]*c, i + 1)
        tails = tails.map {|x| [candidates[i]] * c + x}
        ans += tails
        c += 1
      end
      i += 1
    end
    ans
  end
end
