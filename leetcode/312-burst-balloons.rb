# @param {Integer[]} nums
# @return {Integer}
def max_coins(nums)
  scores = nums.map { nums.map { |x| 0 } }
  nums.each_with_index { |x, i| scores[i][i] = brust(i, nums) }
  s = nums.size
  if s == 0
    return 0
  end
  (2..s).each do |k|
    (0..s-k).each do |i|
      scores[i][i+k-1] = (i..i+k-1).map { |j| nums[j] * get_num(i-1, nums) * get_num(i+k, nums) + get_score(i, j-1, scores) + get_score(j+1, i+k-1, scores) }.max
    end
  end
  scores[0][s-1]
end

def get_score(i, j, scores)
  if i > j
    0
  else
    scores[i][j]
  end
end

def brust(i, nums)
  get_num(i-1, nums) * nums[i] * get_num(i+1, nums)
end

def get_num(i, nums)
  if i < 0 or i >= nums.size
    1
  else
    nums[i]
  end
end

puts max_coins([3, 1, 5, 8])
