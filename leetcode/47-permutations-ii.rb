# @param {Integer[]} nums
# @return {Integer[][]}
def permute_unique(nums)
  used = nums.map { false }  
  nums = nums.sort
  permute(nums, used, nums.size)
end


def permute(nums, used, n)
  return [[]] if n == 0
  res = []
  i = 0
  while i < nums.size
    unless used[i]
      if i == 0 or nums[i] != nums[i-1] or (nums[i] == nums[i-1] and used[i-1])
        used[i] = true
        tail = permute(nums, used, n-1).map {|x| x.unshift nums[i]}
        used[i] = false
        res += tail
      end
    end
    i += 1
  end
  res
end
