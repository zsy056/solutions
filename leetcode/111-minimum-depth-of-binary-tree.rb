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
def min_depth(root)
  q = [root] 
  l = 0
  while true
    level = q.select {|i| not i.nil?}
    break if level.empty?
    l += 1
    leaf_idx = level.index {|i| i.left.nil? and i.right.nil?}
    break unless leaf_idx.nil?
    q = level.flat_map {|x| [x.left, x.right]}
  end
  l
end
