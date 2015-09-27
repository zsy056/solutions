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
  ppath = get_path root, p, []
  qpath = get_path root, q, []
  i = 0
  while i < ppath.size and i < qpath.size and ppath[i] == qpath[i]
    i += 1
  end
  ppath[i-1]
end

def get_path(root, target, path)
  if root.nil?
    []
  elsif root == target
    path << root
    path
  else
    path << root
    left = get_path root.left, target, path
    right = left.empty? ? get_path(root.right, target, path) : left
    path.pop if right.empty?
    right
  end
end
