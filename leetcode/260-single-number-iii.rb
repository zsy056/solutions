# @param {Integer[]} nums
# @return {Integer[]}
def single_number(nums)
  t = nums.inject(0) {|l, n| l ^ n}  
  i = 0
  while ((t >> i) & 1) != 1
    i += 1
  end
  nums.inject([0, 0]) do |r, x|
    if ((x >> i) & 1) == 0
      r[0] ^= x
    else
      r[1] ^= x
    end
    r
  end
end
