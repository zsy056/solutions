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
def insertion_sort_list(head)
  return nil if head.nil?
  dummy = ListNode.new 0  
  remain = ListNode.new 0
  dummy.next = head
  last = head.val
  chead = head.next
  to_insert = head
  remain_head = remain
  while not chead.nil?
    if chead.val >= last
      to_insert.next = chead
      to_insert = chead
      last = chead.val
    else
      remain_head.next = chead
      remain_head = chead
    end
    chead = chead.next
  end
  remain_head.next = nil
  to_insert.next = nil
  chead = remain.next
  while not chead.nil?
    c = dummy
    while (not c.next.nil?) and c.next.val < chead.val
      c = c.next
    end
    tmp = chead.next
    chead.next = c.next
    c.next = chead
    chead = tmp
  end
  dummy.next
end
