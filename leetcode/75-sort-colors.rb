# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def sort_colors(nums)
  r, w, b = 0, 0, 0
  nums.each do |x|
    if x == 0
      r += 1
    elsif x == 1
      w += 1
    else
      b += 1
    end
  end
  nums.each_with_index do |x, idx|
    if r != 0
      nums[idx] = 0
      r -= 1
    elsif w != 0
      nums[idx] = 1
      w -= 1
    else
      nums[idx] = 2
      b -= 1
    end
  end
end
