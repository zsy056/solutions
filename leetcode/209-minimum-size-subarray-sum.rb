# @param {Integer} s
# @param {Integer[]} nums
# @return {Integer}
def min_sub_array_len(s, nums)
  return 0 if nums.empty?
  i = 0
  j = 1
  sum = nums[0]
  min_length = nil
  while j < nums.size
    if sum < s
      sum += nums[j]
      j += 1
    end
    while sum >= s and i < j
      min_length = min_length.nil? ? j-i : [j-i, min_length].min
      sum -= nums[i]
      i += 1
    end
  end

  min_length.nil? ? 0 : min_length
end
