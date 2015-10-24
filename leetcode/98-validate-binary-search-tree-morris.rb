# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Boolean}
def is_valid_bst(root)
  last = nil  
  while not root.nil?
    prev = root.left
    while (not prev.nil?) and (not prev.right.nil?) and (prev.right != root)
      prev = prev.right
    end
    if prev.nil?
      last, valid = visit last, root
      return false unless valid
      root = root.right
    elsif prev.right == root
      prev.right = nil
      last, valid = visit last, root
      return false unless valid
      root = root.right
    else
      prev.right = root
      root = root.left
    end
  end
  true
end

def visit(last, node)
  [node.val, (last.nil? or last < node.val)]
end
