# @param {Integer[]} nums
# @return {Integer[]}
def majority_element(nums)
  a = nil
  ac = 0
  b = nil
  bc = 0
  nums.each do |x|
    if ac == 0 and (bc == 0 or b != x)
      a = x
      ac = 1
    elsif ac != 0 and a == x
      ac += 1
    elsif bc == 0
      b = x
      bc = 1
    elsif b == x
      bc += 1
    else
      bc -= 1
      ac -= 1
    end
  end
  [ac != 0 ? a : nil, bc != 0 ? b : nil].select {|x| nums.inject(0) {|c, y| c += y == x ? 1 : 0} > nums.size / 3}
end
