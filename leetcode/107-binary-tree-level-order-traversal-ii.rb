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
def level_order_bottom(root)
  res = []
  level = 0
  q = [[root, 0]]
  nodes = []
  while not q.empty?
    cnt, clevel = q.shift
    next if cnt.nil?
    if clevel != level
      level = clevel
      res.push nodes
      nodes = []
    end
    nodes.push cnt.val
    q.push [cnt.left, clevel+1]
    q.push [cnt.right, clevel+1]
  end
  res.push nodes unless nodes.empty?
  res.reverse
end
