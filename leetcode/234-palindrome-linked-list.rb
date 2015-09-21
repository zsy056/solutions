# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @return {Boolean}
def is_palindrome(head)
  mid = get_middle head  
  reversed = reverse mid
  p1 = head
  p2 = reversed
  while (not p1.nil?) and (not p2.nil?)
    if p1.val != p2.val
      return false
    end
    p1 = p1.next
    p2 = p2.next
  end
  true
end


def reverse(head)
  return head if head.nil?
  p1 = head
  p2 = head.next
  p1.next = nil
  while not p2.nil?
    tmp = p2.next
    p2.next = p1
    p1 = p2
    p2 = tmp
  end
  p1
end


def get_middle(head)
  return head if head.nil?
  p1 = head
  p2 = head
  while not p2.nil?
    p1 = p1.next
    p2 = p2.next
    break if p2.nil?
    p2 = p2.next
  end
  p1
end

