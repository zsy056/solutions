# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} k
# @return {ListNode}
def reverse_k_group(head, k)
  p1 = head
  p2 = head
  dummy = ListNode.new 0
  dummy.next = head
  prev_tail = dummy
  while not p1.nil?
    i = 0
    while i < k and not p2.nil?
      p2 = p2.next
      i += 1
    end
    break if i != k
    new_head, new_tail = reverse p1, p2
    new_tail.next = p2
    prev_tail.next = new_head
    prev_tail = new_tail
    p1 = p2
  end
  dummy.next
end


def reverse(head, e)
  return [nil, nil] if head.nil?
  old_head = head
  p1 = head
  p2 = head.next
  while not p2.nil? and p2 != e
    tmp = p2.next
    p2.next = p1
    p1 = p2
    p2 = tmp
  end
  [p1, old_head]
end
