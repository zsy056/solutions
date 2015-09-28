# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {Integer[]} inorder
# @param {Integer[]} postorder
# @return {TreeNode}
def build_tree(inorder, postorder)
  tree inorder, 0, inorder.size, postorder, postorder.size  
end


def tree(inorder, ib, ie, postorder, pe)
  if ib >= ie or pe <= 0
    nil
  else
    root = TreeNode.new postorder[pe-1]
    inorder_idx = inorder.find_index postorder[pe-1]
    root.right = tree inorder, inorder_idx+1, ie, postorder, pe-1
    root.left = tree inorder, ib, inorder_idx, postorder, pe-1-(ie-inorder_idx-1)
    root
  end
end
