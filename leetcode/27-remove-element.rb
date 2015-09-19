# @param {Integer[]} nums
# @param {Integer} val
# @return {Integer}
def remove_element(nums, val)
  b = 0  
  nums.each do |num|
    if num != val
      nums[b] = num
      b += 1
    end
  end
  b
end
