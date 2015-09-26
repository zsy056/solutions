# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @param {Integer} k
# @return {Integer}
def kth_smallest(root, k)
   c = 0  
   while not root.nil?
     prev = root.left
     while (not prev.nil?) and (not prev.right.nil?) and prev.right != root
       prev = prev.right
     end
     if prev.nil? or prev.right == root
       c += 1
       return root.val if c == k
       root = root.right
     else
       prev.right = root
       root = root.left
     end
   end
end
