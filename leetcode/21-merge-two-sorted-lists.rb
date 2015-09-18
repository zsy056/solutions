# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def merge_two_lists(l1, l2)
  head = ListNode.new 0
  current = head
  while not l1.nil? and not l2.nil?
    if l1.val <= l2.val 
      current.next = l1
      current = l1
      l1 = l1.next
    else
      current.next = l2
      current = l2
      l2 = l2.next
    end
  end
  while not l1.nil?
    current.next = l1
    current = l1
    l1 = l1.next
  end
  while not l2.nil?
    current.next = l2
    current = l2
    l2 = l2.next
  end
  head.next
end
