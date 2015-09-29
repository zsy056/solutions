# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer[][]}
def zigzag_level_order(root)
  level = [root].select {|x| not x.nil?}
  ans = []
  reverse = false
  while not level.empty?
    level_val = level.map {|x| x.val}
    ans.push(reverse ? level_val.reverse : level_val)
    reverse = (not reverse)
    level = level.flat_map {|x| [x.left, x.right].select {|child| not child.nil?}}
  end
  ans
end
