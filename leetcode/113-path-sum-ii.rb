# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @param {Integer} sum
# @return {Integer[][]}
def path_sum(root, sum)
  paths = []  
  get_path root, 0, sum, [], paths
  paths
end


def get_path(root, current_sum, sum, path, paths)
  if (not root.nil?) and root.left.nil? and root.right.nil?
    path.push root.val
    paths << path.clone if current_sum + root.val == sum
    path.pop
  elsif not root.nil?
    path.push root.val
    get_path root.left, current_sum + root.val, sum, path, paths unless root.left.nil?
    get_path root.right, current_sum + root.val, sum, path, paths unless root.right.nil?
    path.pop
  end
end
