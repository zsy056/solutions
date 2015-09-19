# @param {Integer[]} nums
# @return {Integer}
def rob(nums)
  rob = Array.new nums.size+1, 0
  nrob = Array.new nums.size+1, 0
  nums.each_with_index do |num, i|
    rob[i+1] = [nrob[i] + num, rob[i]].max
    nrob[i+1] = [rob[i], nrob[i]].max
  end
  [rob[nums.size], nrob[nums.size]].max
end
