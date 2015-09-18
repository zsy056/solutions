require 'set'

# @param {Integer[]} nums
# @return {Boolean}
def contains_duplicate(nums)
  s = Set.new
  nums.each do |n|
    return true if s.include? n
    s.add n
  end
  false
end
