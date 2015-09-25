# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def search(nums, target)
  b = 0
  e = nums.size - 1
  while b < e
    mid = (e - b) / 2 + b
    if nums[mid] == target
      b = mid
      break
    elsif nums[b] == target
      break
    elsif nums[e] == target
      b = e
      break
    elsif nums[mid] > target
      if (nums[b] < nums[mid] and nums[b] < target) or nums[b] > nums[mid]
        e = mid - 1
      else
        b = mid + 1
      end
    else
      if (nums[mid] < nums[e] and nums[e] > target) or (nums[mid] > nums[e] and nums[e] < target)
        b = mid + 1
      else
        e = mid - 1
      end
    end
  end
  nums[b] == target ? b : -1
end
