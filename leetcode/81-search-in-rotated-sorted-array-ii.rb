# @param {Integer[]} nums
# @param {Integer} target
# @return {Boolean}
def search(nums, target)
  -1 != _search(nums, target, 0, nums.size - 1)
end


def _search(nums, target, b, e)
  if b < e
    mid = (e - b) / 2 + b
    if nums[mid] == target
      b = mid
    elsif nums[mid] < target and nums[mid] < nums[e] and nums[e] >= target
      b = _search(nums, target, mid+1, e)
    elsif nums[mid] > target and nums[b] < nums[mid] and nums[b] <= target
      b = _search(nums, target, b, mid-1)
    else
      b = _search(nums, target, b, mid-1)
      b = b == -1 ? _search(nums, target, mid+1, e) : b
    end
  end
  nums[b] == target ? b : -1
end
