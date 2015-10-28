# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode[]} lists
# @return {ListNode}
def merge_k_lists(lists)
  if lists.size <= 2
    merge lists
  else
    mid = lists.size / 2
    merge [merge_k_lists(lists[0...mid]), merge_k_lists(lists[mid..-1])]
  end
end


def merge(lists)
  dummy = ListNode.new 0
  current = dummy
  lists.select! { |l| not l.nil? }
  while not lists.empty?
    node = lists.min { |a, b| a.val <=> b.val }
    current.next = node
    current = current.next
    idx = lists.index node
    lists[idx] = node.next
    lists.select! { |l| not l.nil? }
  end
  dummy.next
end
