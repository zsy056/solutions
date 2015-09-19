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
def is_balanced(root)
  a = _is_balanced root
  a[0]
end


def _is_balanced(root)
  return [true, 0] if root.nil?
  left_balanced, left_h = _is_balanced root.left
  return [false, 0] unless left_balanced
  right_balanced, right_h = _is_balanced root.right
  if right_balanced
    [(left_h-right_h).abs <= 1, [left_h, right_h].max + 1]
  else
    [false, 0]
  end
end
