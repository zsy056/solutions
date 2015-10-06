# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def next_permutation(nums)
  i = nums.size - 1
  while i > 0
    if nums[i-1] < nums[i]
      j = nums.size - 1
      while j >= i
        break if nums[j] > nums[i-1]
        j -= 1
      end
      nums[i-1], nums[j] = nums[j], nums[i-1]
      break
    end
    i -= 1
  end
  nums[i..-1] = nums[i..-1].sort
end
