require 'set'

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
  min_max_valid(root)[2]  
end


def min_max_valid(root)
  return [nil, nil, true] if root.nil?
  lmin, lmax, lvalid = min_max_valid root.left
  return [nil, nil, false] if (not lvalid.nil?) and (not lvalid)
  rmin, rmax, rvalid = min_max_valid root.right
  return [nil, nil, false] if (not rvalid.nil?) and (not rvalid)
  vals = [lmax, root.val, rmin].select { |x| not x.nil? }
  sorted_vals = vals.sort
  [lmin.nil? ? root.val : lmin, rmax.nil? ? root.val : rmax, (vals == sorted_vals and Set.new(vals).size == vals.size)]
end
