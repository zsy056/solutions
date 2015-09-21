# @param {Integer[]} nums
# @return {String[]}
def summary_ranges(nums)
  last = nil
  start = nil
  res = []
  size = nums.size
  nums.each_with_index do |n, idx|
    if n - 1 != last
      if (not last.nil?) and (not start == last)
        res[-1] += "->#{last}"
      end
      res << n.to_s
      start = n
    elsif idx == size - 1
      res[-1] += "->#{n}"
    end
    last = n
  end
  res
end
