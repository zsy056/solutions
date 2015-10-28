# @param {Integer[]} nums
# @param {Integer} k
# @return {Integer[]}
def max_sliding_window(nums, k)
  q = []  # [[val, idx]]
  res = []
  nums.each_with_index do |num, i|
    if i < k
      while (not q.empty?) and q[-1][0] < num
        q.pop
      end
      q.push [num, i]
      res.push q[0][0] if i == k - 1
    else
      while (not q.empty?) and q[0][1] <= i - k 
        q.shift
      end
      while (not q.empty?) and q[-1][0] < num
        q.pop
      end
      q.push [num, i]
      res.push q[0][0]
    end
  end
  res
end
