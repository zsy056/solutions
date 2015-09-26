# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Void} Do not return anything, modify root in-place instead.
def flatten(root)
  _flattern(root)[0]
end


def _flattern(root)
  if root.nil?
    [nil, nil]
  elsif root.left.nil? and root.right.nil?
    root.left = nil
    root.right = nil
    [root, root]
  else
    left_start, left_end = _flattern root.left
    right_start, right_end = _flattern root.right
    root.left = nil
    if left_start.nil?
      root.right = right_start
      [root, right_end]
    else
      root.right = left_start
      left_end.right = right_start
      [root, right_end.nil? ? left_end : right_end]
    end
  end
end
