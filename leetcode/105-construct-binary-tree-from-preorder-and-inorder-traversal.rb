# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {Integer[]} preorder
# @param {Integer[]} inorder
# @return {TreeNode}
def build_tree(preorder, inorder)
  tree preorder, 0, inorder, 0, inorder.size  
end


def tree(preorder, pb, inorder, ib, ie)
  if ib >= ie or pb >= preorder.size
    nil
  else
    mid_idx = inorder.find_index preorder[pb]
    root = TreeNode.new preorder[pb]
    root.left = tree preorder, pb+1, inorder, ib, mid_idx
    root.right = tree preorder, pb+mid_idx-ib+1, inorder, mid_idx+1, ie
    root
  end
end
