# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @return {ListNode}
def swap_pairs(head)
  return nil if head.nil?
  p1 = head
  p2 = head.next
  return p1 if p2.nil?
  p1.next = swap_pairs p2.next
  p2.next = p1
  p2
end
