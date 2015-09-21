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
def inorder_traversal(root)
  res = []  
  while not root.nil?
    prev = root.left
    if prev.nil?
      res << root.val
    else
      while (not prev.right.nil?) and prev.right != root
        prev = prev.right
      end
      if prev.right == root
        prev.right = nil
        res << root.val
        root = root.right
        next
      else
        prev.right = root
      end
    end
    root = root.left.nil? ? root.right : root.left
  end
  res
end
