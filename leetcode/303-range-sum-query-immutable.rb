class NumArray

  # Initialize your data structure here.
  # @param {Integer[]} nums
  def initialize(nums)
    @cache = nums.map { 0 }
    if nums.size > 0
      @cache[0] = nums[0]
      i = 1
      while i < nums.size
        @cache[i] = @cache[i-1] + nums[i]
        i += 1
      end
    end
  end

  # @param {Integer} i
  # @param {Integer} j
  # @return {Integer}
  def sum_range(i, j)
    i == 0 ? @cache[j] : @cache[j] - @cache[i-1]
  end
end

# Your NumArray object will be instantiated and called as such:
# num_array = NumArray.new(nums)
# num_array.sum_range(0, 1)
# num_array.sum_range(0, 2)
