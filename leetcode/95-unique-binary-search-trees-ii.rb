# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {Integer} n
# @return {TreeNode[]}
def generate_trees(n)
  generate((1..n).map {|x| x}, 0, n)
end


def generate(nums, b, e)
  i = b
  res = []
  while i < e
    left = generate(nums, b, i)
    right = generate(nums, i+1, e)
    ans = left.flat_map do |l|
      right.map do |r|
        root = TreeNode.new nums[i]
        root.left = l
        root.right = r
        root
      end
    end
    res += ans
    i += 1
  end
  res.empty? ? [nil] : res
end
