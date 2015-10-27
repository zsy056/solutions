# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Void} Do not return anything, modify root in-place instead.
def recover_tree(root)
  p1, p2 = nil, nil  
  last = nil
  while not root.nil?
    prev = root.left
    while (not prev.nil?) and (not prev.right.nil?) and prev.right != root
      prev = prev.right
    end
    if prev.nil? or prev.right == root
      root, last, p1, p2 = visit root, last, p1, p2
      prev.right = nil unless prev.nil?
    elsif prev.right.nil?
      prev.right = root
      root = root.left
    end
  end
  p1.val, p2.val = p2.val, p1.val
end


# [next, last, p1, p2]
def visit(root, last, p1, p2)
  if (not last.nil?) and last.val > root.val and p1.nil?
    p1 = last
  end
  if (not last.nil?) and last.val > root.val
    p2 = root
  end
  last = root
  [root.right, last, p1, p2]
end
