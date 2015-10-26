# @param {Integer[]} nums
# @return {Integer}
def find_min(nums)
  b = 0
  e = nums.size - 1
  min = nums[0]
  while b < e
    break if nums[b] < nums[e]
    mid = (e - b) / 2 + b
    if nums[mid] < nums[b]
      b += 1
      e = mid
    elsif nums[mid] > nums[b] or nums[b] != nums[e]
      b = mid + 1
    else
      while b < e and nums[b] == nums[e]
        b += 1
        e -= 1
      end
    end
  end
  [min, nums[b]].min
end
