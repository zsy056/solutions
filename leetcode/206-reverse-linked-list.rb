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
def reverse_list(head)
  return nil if head.nil?
  p1 = head
  p2 = head.next
  p1.next = nil
  while not p2.nil?
    nxt = p2.next
    p2.next = p1
    p1 = p2
    p2 = nxt
  end
  p1
end
