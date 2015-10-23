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
def add_two_numbers(l1, l2)
  carry = 0
  dummy = ListNode.new 0
  current = dummy
  while (not l1.nil?) and (not l2.nil?)
    tmp = carry + l1.val + l2.val
    carry = tmp / 10
    tmp = tmp % 10
    node = ListNode.new tmp
    current.next = node
    current = current.next
    l1 = l1.next
    l2 = l2.next
  end

  l = l1.nil? ? l2 : l1
  while not l.nil?
    tmp = carry + l.val
    carry = tmp / 10
    tmp = tmp % 10
    node = ListNode.new tmp
    current.next = node
    current = current.next
    l = l.next
  end

  while carry > 0
    node = ListNode.new carry % 10
    current.next = node
    current = current.next
    carry = carry / 10
  end

  dummy.next
end
