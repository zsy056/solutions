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
  current = head
  while not current.nil?
    nxt = current.next
    while not nxt.nil? and nxt.val == current.val
      nxt = nxt.next
    end
    current.next = nxt
    current = nxt
  end
  head
end
