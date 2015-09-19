# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)
  return 0 if nums.empty?
  b = 1
  current = nums[0]
  (1...nums.size).each do |i|
    if nums[i] != current
      current = nums[i]
      nums[b] = current
      b += 1
    end
  end
  b
end
