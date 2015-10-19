# @param {Integer[]} nums
# @return {Integer}
def find_duplicate(nums)
  a = nums[0]
  b = nums[0]
  while true
    a = nums[a]
    b = nums[nums[b]]
    break if a == b
  end
  a = nums[0]
  while a != b
    a = nums[a]
    b = nums[b]
  end
  a
end
