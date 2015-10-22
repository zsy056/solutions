# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @return {Void} Do not return anything, modify head in-place instead.
def reorder_list(head)
  return head if head.nil?
  p1 = head
  p2 = head
  while not p2.nil?
    p2 = p2.next
    break if p2.nil?
    p2 = p2.next
    break if p2.nil?
    p1 = p1.next
  end
  p2 = reverse p1.next
  p1.next = nil
  current = head
  p1 = head.next
  flag = 1
  while not (p1.nil? and p2.nil?)
    if flag == 1
      current.next = p2
      p2 = p2.next
    else
      tmp = p1.next
      current.next = p1
      p1 = tmp
    end
    current = current.next
    flag = 1 - flag
  end
  head
end


def reverse(head)
  if head.nil?
    head
  else
    p1 = head
    p2 = head.next
    while not p2.nil?
      tmp = p2.next
      p2.next = p1
      p1 = p2
      p2 = tmp
    end
    head.next = nil
    p1
  end
end
