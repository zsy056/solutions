# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {Integer[]} nums
# @return {TreeNode}
def sorted_array_to_bst(nums)
  n = nums.size
  if n == 0
    nil
  elsif n == 1
    TreeNode.new nums[0]
  else
    i = n / 2
    left = sorted_array_to_bst(nums[0...i])
    right = sorted_array_to_bst(nums[i+1..-1])
    node = TreeNode.new nums[i]
    node.left = left
    node.right = right
    node
  end
end
