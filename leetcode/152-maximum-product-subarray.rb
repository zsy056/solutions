# @param {Integer[]} nums
# @return {Integer}
def max_product(nums)
  pos = nil
  neg = nil
  maxp = nil
  i = 0
  while i < nums.size
    if nums[i] > 0
      tpos = (pos.nil? or pos == 0) ? nums[i] : pos * nums[i]
      tneg = (neg.nil? or neg == 0) ? nil : neg * nums[i]
      pos, neg = tpos, tneg
    elsif nums[i] < 0
      tneg = (pos.nil? or pos == 0) ? nums[i] : pos * nums[i]
      tpos = (neg.nil? or neg == 0) ? nil : neg * nums[i]
      pos, neg = tpos, tneg
    elsif nums[i] == 0
      pos = 0
      neg = 0
    end
    maxp = [maxp, pos, neg].select{|x| not x.nil?}.max
    i += 1
  end
  maxp.nil? ? 0 : maxp
end
