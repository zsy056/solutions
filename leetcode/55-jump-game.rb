# @param {Integer[]} nums
# @return {Boolean}
def can_jump(nums)
  current_range = 0
  nums.each_with_index do |max_step, i|
    return false if current_range < i
    next if i + max_step <= current_range or i == nums.size - 1
    current_range = i + max_step
    return true if current_range >= nums.size - 1
  end
  current_range >= nums.size - 1
end
