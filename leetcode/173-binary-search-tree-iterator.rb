# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

class BSTIterator
  # @param {TreeNode} root
  def initialize(root)
    @root = root
  end

  # @return {Boolean}
  def has_next
    not @root.nil?
  end

  # @return {Integer}
  def next
    val = 0
    while has_next
      prev = @root.left
      while (not prev.nil?) and (not prev.right.nil?) and prev.right != @root
        prev = prev.right
      end
      if prev.nil?
        val = @root.val
        @root = @root.right
        break
      elsif prev.right == @root
        prev.right = nil
        val = @root.val
        @root = @root.right
        break
      else
        prev.right = @root
        @root = @root.left
      end
    end
    val
  end
end

# Your BSTIterator will be called like this:
# i, v = BSTIterator.new(root), []
# while i.has_next()
#    v << i.next
# end
