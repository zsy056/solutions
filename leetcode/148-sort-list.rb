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
def sort_list(head)
  return nil if head.nil?
  return head if head.next.nil?
  p1 = head
  p2 = head
  while true
    p2 = p2.next
    break if p2.nil?
    p2 = p2.next
    break if p2.nil?
    p1 = p1.next
  end
  h2 = p1.next
  p1.next = nil
  h1 = sort_list head
  h2 = sort_list h2
  dummy = ListNode.new 0
  current = dummy
  while (not h1.nil?) and (not h2.nil?)
    if h1.val < h2.val
      current.next = h1
      h1 = h1.next
    else
      current.next = h2
      h2 = h2.next
    end
    current = current.next
  end
  remain = h1.nil? ? h2 : h1
  current.next = remain
  dummy.next
end
