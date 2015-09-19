# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def move_zeroes(nums)
  return nums if nums.empty?
  b = 0
  nums.each do |num|
    if num != 0
      nums[b] = num
      b += 1
    end
  end
  while b < nums.size
    nums[b] = 0
    b += 1
  end
end
