# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer}
def sum_numbers(root)
  $sum = 0
  traverse root, 0
  $sum
end


$sum = 0


def traverse(root, current)
  unless root.nil?
    current = current * 10 + root.val
    if root.left.nil? and root.right.nil?
      $sum += current
    else
      traverse root.left, current
      traverse root.right, current
    end
  end
end
