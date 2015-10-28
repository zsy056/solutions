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
def max_path_sum(root)
  return 0 if root.nil?
  _max_sum(root).select { |x| not x.nil? }.max  
end

# [can_expand, no_expand]
def _max_sum(root)
  return [nil, nil] if root.nil?
  left_e, left_ne = _max_sum root.left
  right_e, right_ne = _max_sum root.right
  e = root.val + [left_e, right_e, 0].select { |x| not x.nil? }.max
  all_ne = (left_e.nil? ? 0 : left_e) + (right_e.nil? ? 0 : right_e) + root.val
  ne = [left_ne, right_ne, left_e, right_e, all_ne].select { |x| not x.nil? }.max
  [e, ne]
end
