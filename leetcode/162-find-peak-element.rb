# @param {Integer[]} nums
# @return {Integer}
def find_peak_element(nums)
  n = nums.size  
  nums.each_with_index do |x, idx|
    left = (idx == 0 or nums[idx-1] < x)
    right = (idx == n-1 or nums[idx+1] < x)
    return idx if (left and right)
  end
  0
end

