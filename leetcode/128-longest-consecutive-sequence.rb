require 'set'

# @param {Integer[]} nums
# @return {Integer}
def longest_consecutive(nums)
  heads = Hash.new # head -> tail
  tails = Hash.new # tail -> head
  all = Set.new
  nums.each do |num|
    next if all.include? num
    all.add num
    old_tail = heads[num + 1]
    old_head = tails[num - 1]
    if (not old_tail.nil?) and (not old_head.nil?)
      heads[old_head] = old_tail
      tails[old_tail] = old_head
      heads.delete num + 1
      tails.delete num - 1
    elsif not old_head.nil?
      heads[old_head] = num
      tails[num] = old_head
      tails.delete num - 1
    elsif not old_tail.nil?
      tails[old_tail] = num
      heads[num] = old_tail
      heads.delete num + 1
    elsif (not heads.include? num) and (not tails.include? num)
      heads[num] = num
      tails[num] = num
    end
  end
  heads.inject(0) { |max, x| [max, x[1] - x[0] + 1].max }
end

