# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def three_sum_closest(nums, target)
  i = 0
  n = nums.size
  nums = nums.sort
  closest = nil
  while i < n
    j = i + 1
    k = n - 1
    while j < k
      psum = nums[i] + nums[j] + nums[k]
      p psum
      closest = psum if closest.nil? or (closest-target).abs > (psum-target).abs
      if psum == target
        return psum
      elsif psum < target
        j += 1
      else
        k -= 1
      end
    end
    i += 1
  end
  closest
end
