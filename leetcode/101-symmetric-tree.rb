# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Boolean}
def is_symmetric(root)
  root.nil? or _is_symmetric(root.left, root.right)
end

def _is_symmetric(a, b)
  if a.nil? and b.nil?
    true
  elsif a.nil? or b.nil?
    false
  else
    a.val == b.val and _is_symmetric(a.left, b.right) and _is_symmetric(a.right, b.left)
  end
end
