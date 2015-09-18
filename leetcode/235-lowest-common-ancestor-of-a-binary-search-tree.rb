# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @param {TreeNode} p
# @param {TreeNode} q
# @return {TreeNode}
def lowest_common_ancestor(root, p, q)
  path_p, path_q = (get_path root, p), (get_path root, q)
  (path_p.select {|x| path_q.include? x })[-1]
end

def get_path(root, p)
  path = [root]
  while root.val != p.val 
    root = root.val < p.val ? root.right : root.left
    path << root
  end
  path
end
