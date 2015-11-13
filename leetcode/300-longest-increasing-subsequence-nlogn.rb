# @param {Integer[]} nums
# @return {Integer}
def length_of_lis(nums)
  return 0 if nums.empty?
  seq_ends = Array.new nums.size+1, 0
  seq_ends[1] = nums[0]
  max_len = 2
  i = 1
  while i < nums.size
    b = 1
    e = max_len
    while b < e - 1
      mid = (e - b) / 2 + b
      if seq_ends[mid] == nums[i]
        break
      elsif seq_ends[mid] < nums[i]
        b = mid
      else
        e = mid
      end
    end
    if b == 1 and seq_ends[1] > nums[i]
      seq_ends[1] = nums[i]
    elsif seq_ends[b] < nums[i]
      seq_ends[b+1] = nums[i]
      max_len += 1 if b + 1 == max_len
    end
    i += 1
  end
  max_len - 1
end
