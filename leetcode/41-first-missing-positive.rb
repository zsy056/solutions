# @param {Integer[]} nums
# @return {Integer}
def first_missing_positive(nums)
  i, j = 0, 0
  while j < nums.size
    if nums[j] > 0
      nums[i] = nums[j]
      i += 1
    end
    j += 1
  end
  pos_count = i
  while i < j
    nums[i] = 0
    i += 1
  end
  i = 0
  while i < pos_count
    idx = nums[i].abs
    if idx <= nums.size and nums[idx-1] == 0
      nums[idx-1] = -1
    elsif idx <= nums.size and nums[idx-1] > 0
      nums[idx-1] = -nums[idx-1]
    end
    i += 1
  end
  i = 0
  while i < nums.size
    break if nums[i] >= 0
    i += 1
  end
  i + 1
end
