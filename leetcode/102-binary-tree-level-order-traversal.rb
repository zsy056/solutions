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
def level_order(root)
  total = []  
  q = [[root, 0]]
  level = []
  while not q.empty?
    node, cidx = q.shift
    next if node.nil?
    if total.size != cidx
      total.push level
      level = []
    end
    level.push node.val
    q.push [node.left, total.size + 1]
    q.push [node.right, total.size + 1]
  end
  total.push level unless root.nil?
  total
end
