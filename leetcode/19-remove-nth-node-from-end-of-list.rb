# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} n
# @return {ListNode}
def remove_nth_from_end(head, n)
  dummy = ListNode.new 0
  dummy.next = head
  p1 = dummy
  p2 = dummy
  n.times {|i| p1 = p1.next}
  while not (p1.nil? or p1.next.nil?)
    p1 = p1.next
    p2 = p2.next
  end
  p2.next = p2.next.next
  dummy.next
end
