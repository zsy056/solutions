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
def rotate_right(head, k)
  n = length head  
  return head if n == 0
  k = (n - k % n) % n
  return head if k == 0
  new_head, p = nil, head
  while k > 1
    p = p.next
    k -= 1
  end
  new_head = p.next
  p.next = nil
  p = new_head
  while not p.next.nil?
    p = p.next
  end
  p.next = head
  new_head
end


def length(head)
  counter = 0
  while not head.nil?
    head = head.next
    counter += 1
  end
  counter
end
