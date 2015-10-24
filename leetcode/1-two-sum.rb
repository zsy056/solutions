# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
  num_map = nums.map.with_index { |x, i| [x, i + 1] }.to_h
  nums.each_with_index do |num, i|
    num2 = target - num
    return [i+1, num_map[num2]].sort if num_map.include? num2 and num_map[num2] != i+1
  end
end
