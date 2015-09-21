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
def preorder_traversal(root)
  res = []  
  while not root.nil?
    prev = root.left
    while (not prev.nil?) and (not prev.right.nil?) and (prev.right != root)
      prev = prev.right
    end
    if prev.nil?
      res << root.val
    else
      if prev.right.nil?
        prev.right = root
        res << root.val
      else
        # visited
        prev.right = nil
        root = root.right
        next
      end
    end
    root = root.left.nil? ? root.right : root.left
  end
  res
end
