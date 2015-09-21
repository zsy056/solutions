# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {String[]}
def binary_tree_paths(root)
  if root.nil?
    []
  else
    left = binary_tree_paths root.left
    right = binary_tree_paths root.right
    (left.empty? and right.empty?) ? [root.val.to_s] : (left + right).map {|s| "#{root.val}->#{s}"}
  end
end
