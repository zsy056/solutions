# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} x
# @return {ListNode}
def partition(head, x)
  small = ListNode.new 0
  large = ListNode.new 0
  sc = small
  lc = large
  while not head.nil?
    if head.val < x
      sc.next = head
      sc = sc.next
    else
      lc.next = head
      lc = lc.next
    end
    head = head.next
  end
  sc.next = large.next
  lc.next = nil
  small.next
end
