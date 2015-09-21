# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}

def search_insert(nums, target)
  _search_insert(nums, target)
end

def _search_insert(nums, target)
  nums << 99999999999
  b = 0
  e = nums.size - 1
  while b < e
    mid = (e - b) / 2 + b
    if nums[mid] == target
      return mid
    elsif nums[mid] > target
      e = mid
    else
      b = mid + 1
    end
  end
  b
end
