# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} val
# @return {ListNode}
def remove_elements(head, val)
  dummy = ListNode.new 0  
  dummy.next = head
  current = dummy
  while (not current.nil?) and (not current.next.nil?)
    while (not current.next.nil?) and current.next.val == val
      current.next = current.next.next
    end
    current = current.next
  end
  dummy.next
end
