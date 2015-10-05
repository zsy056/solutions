# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} m
# @param {Integer} n
# @return {ListNode}
def reverse_between(head, m, n)
  dummy = ListNode.new 0
  dummy.next = head
  i = 1
  p1 = head
  prefix = dummy
  while i < m
    p1 = p1.next
    prefix = prefix.next
    i += 1
  end
  reversed_tail = p1
  
  p2 = p1.next
  while i < n
    tmp = p2.next
    p2.next = p1
    p1 = p2
    p2 = tmp
    i += 1
  end
  prefix.next = p1
  reversed_tail.next = p2

  dummy.next
end
