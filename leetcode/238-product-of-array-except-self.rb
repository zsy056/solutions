# @param {Integer[]} nums
# @return {Integer[]}
def product_except_self(nums)
  a1 = nums.inject([1]) {|a, x| a << (a[-1] * x)} 
  a2 = nums.reverse.inject([1]) {|a, x| a << (a[-1] * x)}.reverse
  a = Array.new(nums.size + 2)
  (1..nums.size).each do |i|
    a[i] = a1[i-1] * a2[i]
  end
  a[1..-2]
end
