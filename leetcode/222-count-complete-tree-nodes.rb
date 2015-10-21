# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer}
def count_nodes(root)
  return 0 if root.nil?
  left_h = get_height(root) { |c| c.left }
  right_h = get_height(root) { |c| c.right }
  if left_h == right_h
    2 ** left_h - 1
  else
    1 + count_nodes(root.left) + count_nodes(root.right)
  end
end

def get_height(root)
  current = root
  h = 0
  while not current.nil?
    current = yield current
    h += 1
  end
  h
end

