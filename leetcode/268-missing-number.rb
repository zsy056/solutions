# @param {Integer[]} nums
# @return {Integer}
def missing_number(nums)
  n = nums.size
  tsum = n * (nums.size + 1) / 2
  sum = nums.inject(0) {|s, x| s + x}
  tsum - sum
end
