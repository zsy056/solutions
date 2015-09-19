# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @param {Integer} sum
# @return {Boolean}
def has_path_sum(root, sum)
  if root.nil?
    false
  elsif root.left.nil? and root.right.nil?
    sum == root.val
  else
    left = has_path_sum root.right, sum - root.val
    left or (has_path_sum root.left, sum - root.val)
  end
end
