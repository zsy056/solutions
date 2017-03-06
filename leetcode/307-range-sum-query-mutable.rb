class IntervalNode
  attr_reader :i, :j, :val, :children

  def initialize(val, i, j)
    @val = val
    @i = i
    @j = j
    @children = []
  end

  def update(val, i)
    delta = 0
    if @i == @j and @i == i
      delta = val - @val
      @val = val
    elsif @i <= i and @j >= i
      if i <= @i + (@j - @i)/2
        delta = @children[0].update val, i
      else
        delta = @children[1].update val, i
      end
      @val += delta
    end
    delta
  end

  def sum(i, j)
    if i <= @i and j >= @j
      @val
    elsif i > @j or j < @i
      0
    else
      @children.map { |c| c.sum(i, j) }.inject(0) { |a, x| a + x }
    end
  end

  def self.get_tree(nums, i, j)
    if nums.size == 0
      nil
    elsif i == j
      IntervalNode.new nums[i], i, i
    else
      left = get_tree(nums, i, i + (j - i)/2)
      right = get_tree(nums, i+(j-i)/2+1, j)
      parent = IntervalNode.new(left.val + right.val, i, j)
      parent.children << left
      parent.children << right
      parent
    end
  end

  def to_s
    "[#{@i}-#{@j} val=#{@val} [#{@children.map {|x| x.to_s}.join ','}]]"
  end
end

class NumArray

  # Initialize your data structure here.
  # @param {Integer[]} nums
  def initialize(nums)
    @tree = IntervalNode::get_tree(nums, 0, nums.size-1)
  end

  # @param {Integer} i
  # @param {Integer} val
  # @return {Integer}
  def update(i, val)
    @tree.update val, i
  end

  # @param {Integer} i
  # @param {Integer} j
  # @return {Integer}
  def sum_range(i, j)
    @tree.sum i, j
  end

  def to_s
    @tree.to_s
  end
end

# Your NumArray object will be instantiated and called as such:
num_array = NumArray.new([9, -8])
puts num_array.to_s
puts num_array.update(0, 3)
puts num_array.to_s
puts num_array.sum_range(1, 1)
puts num_array.sum_range(0, 1)

