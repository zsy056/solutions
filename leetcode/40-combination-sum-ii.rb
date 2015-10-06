# @param {Integer[]} candidates
# @param {Integer} target
# @return {Integer[][]}
def combination_sum2(candidates, target)
  candidates = candidates.sort  
  used = candidates.map { false }
  comb_sum candidates, used, target, 0
end


def comb_sum(candidates, used, target, b)
  if target == 0
    [[]]
  elsif target < 0
    []
  else
    ans = []
    i = b
    while i < candidates.size
      unless used[i]
        if i == 0 or candidates[i] != candidates[i-1] or used[i-1]
          used[i] = true
          prev = comb_sum(candidates, used, target - candidates[i], i + 1).map {|x| x.unshift candidates[i]}
          used[i] = false
          ans += prev
        end
      end
      i += 1
    end
    ans
  end
end
