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
def postorder_traversal(root)
  res = []
  return res if root.nil?
  stk = [[root, 0]]
  while not stk.empty?
    if stk[-1][0].left.nil? and stk[-1][0].right.nil?
      res.push stk.pop[0].val
    elsif stk[-1][1] == 0
      stk[-1][1] = 1
      cnt = stk[-1][0].left
      while not cnt.nil?
        stk.push [cnt, 1]
        cnt = cnt.left
      end
    elsif stk[-1][1] == 1 and not stk[-1][0].right.nil?
      stk[-1][1] = 2
      stk.push [stk[-1][0].right, 0]
    elsif stk[-1][1] == 1
      res.push stk.pop[0].val
    elsif stk[-1][1] == 2
      res.push stk.pop[0].val
    end
  end
  res
end
