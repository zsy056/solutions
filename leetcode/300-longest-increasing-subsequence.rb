# @param {Integer[]} nums
# @return {Integer}
def length_of_lis(nums)
  return 0 if nums.empty?
  lens = nums.map { 1 }
  i = 1
  while i < nums.size
    j = i - 1
    while j >= 0
      lens[i] = [lens[i], lens[j]+1].max if nums[j] < nums[i]
      j -= 1
    end
    i += 1
  end
  lens.max
end
