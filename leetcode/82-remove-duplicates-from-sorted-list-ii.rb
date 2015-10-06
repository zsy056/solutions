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
def delete_duplicates(head)
  return nil if head.nil?
  dummy = ListNode.new 0  
  p = head
  dup = false
  current = dummy
  while (not p.nil?) and (not p.next.nil?)
    while (not p.next.nil?) and p.next.val == p.val
      dup = true
      p = p.next
    end
    unless dup
      current.next = p
      current = current.next
    end
    dup = false
    p = p.next
  end
  current.next = p

  dummy.next
end
