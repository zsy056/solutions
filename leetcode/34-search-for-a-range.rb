# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def search_range(nums, target)
  [lb(nums, target), ub(nums, target)]  
end


def ub(nums, target)
  b = 0
  e = nums.size - 1
  while b < e
    mid = (e - b) / 2 + b
    if nums[mid] == target and (mid == e or nums[mid+1] != target)
      b = mid
      break
    elsif nums[mid] <= target
      b = mid + 1
    else
      e = mid
    end
  end
  nums[b] == target ? b : -1
end


def lb(nums, target)
  b = 0
  e = nums.size - 1
  while b < e
    mid = (e - b) / 2 + b
    if nums[mid] == target and (mid == 0 or nums[mid-1] != target)
      b = mid
      break
    elsif nums[mid] >= target
      e = mid
    else
      b = mid + 1
    end
  end
  nums[b] == target ? b : -1
end
