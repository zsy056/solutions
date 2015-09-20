require 'set'

# @param {Integer[]} nums
# @param {Integer} k
# @return {Boolean}
def contains_nearby_duplicate(nums, k)
  k += 1
  window = Set.new  
  i = 0
  j = 0
  while i < k and i < nums.size
    return true if window.include? nums[i]
    window.add nums[i]
    i += 1
  end
  while i < nums.size
    window.delete nums[j]
    return true if window.include? nums[i]
    window.add nums[i]
    i += 1
    j += 1
  end
  false
end
