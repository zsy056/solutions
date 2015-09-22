# @param {Integer[]} nums
# @return {Integer}
def find_min(nums)
  b = 0
  e = nums.size - 1
  while b < e
    mid = (e - b) / 2 + b
    if nums[mid] > nums[e]
      b = mid + 1
    elsif nums[mid] < nums[mid - 1]
      b = mid
      break
    else
      e = mid - 1
    end
  end
  nums[b]
end
