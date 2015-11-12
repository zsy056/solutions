# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# Encodes a tree to a single string.
#
# @param {TreeNode} root
# @return {string}
def serialize(root)
  res = []
  q = [root]
  while not q.empty?
    res.concat q.map { |x| x.nil? ? x : x.val }
    q = q.select {|x| not x.nil? }.flat_map { |x| [x.left, x.right] }
  end
  res.join ','
end

# Decodes your encoded data to tree.
#
# @param {string} data
# @return {TreeNode}
def deserialize(data)
  if data.nil? or data.length == 0
    nil
  else
    data = data.split(',').map { |x| x == '' ? nil : x.to_i }
    return nil if data[0].nil?
    root = TreeNode.new data[0]
    q = [root]
    i = 1
    while not q.empty?
      q.each do |node|
        node.left = data[i].nil? ? nil : TreeNode.new(data[i])
        node.right = data[i+1].nil? ? nil : TreeNode.new(data[i+1])
        i += 2
      end
      q = q.flat_map { |x| [x.left, x.right] }.select { |x| not x.nil? }
    end
    root
  end
end


# Your functions will be called as such:
# deserialize(serialize(data))
