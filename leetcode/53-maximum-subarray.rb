# @param {Integer[]} nums
# @return {Integer}
def max_sub_array(nums)
  return 0 if nums.empty?
  sum = nums[0]
  nums[1..-1].inject(sum) do |max, x|
    tmp = sum + x
    sum = [x, tmp].max
    (max.nil? or max < sum) ? sum : max
  end
end
