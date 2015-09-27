# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {ListNode} head
# @return {TreeNode}
def sorted_list_to_bst(head)
  nums = []  
  while not head.nil?
    nums << head.val
    head = head.next
  end
  _to_bst nums, 0, nums.size
end


def _to_bst(nums, b, e)
  if b >= e
    nil
  else
    mid = (e - b) / 2 + b
    root = TreeNode.new nums[mid]
    left = _to_bst(nums, b, mid)
    right = _to_bst(nums, mid+1, e)
    root.left = left
    root.right = right
    root
  end
end

