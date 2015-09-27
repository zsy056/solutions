# @param {Integer[]} nums
# @return {Integer}
def rob(nums)
  nums.size == 1 ? rob1(nums, 0, nums.size) : [rob1(nums, 0, nums.size-1), rob1(nums, 1, nums.size)].max  
end


def rob1(nums, b, e)
  return 0 if b >= e
  r = Array.new e-b, 0
  nr = Array.new e-b, 0
  i = b
  while i < e
    if i == b
      r[i-b] = nums[i]
    else
      r[i-b] = nums[i] + nr[i-1-b]
      nr[i-b] = [nr[i-1-b], r[i-1-b]].max
    end
    i += 1
  end
  [nr[e-1-b], r[e-1-b]].max
end
