# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer[]}
def right_side_view(root)
  right_view = []  
  level = [root]
  while not level.empty?
    right_view << level[-1].val unless level[-1].nil?
    level = level.select {|x| not x.nil?}.flat_map {|x| [x.left, x.right]}.select {|x| not x.nil?}
  end
  right_view
end
