class NumMatrix

  # Initialize your data structure here.
  # @param {Integer[][]} matrix
  def initialize(matrix)
    @cache = matrix.map { |x| Array.new x.size, 0 }
    return if matrix.empty?
    m = matrix.size
    n = matrix[0].size
    m.times.each do |i|
      n.times.each do |j|
        @cache[i][j] = matrix[i][j]
        @cache[i][j] += @cache[i][j-1] if j != 0
        @cache[i][j] += @cache[i-1][j] if i != 0
        @cache[i][j] -= @cache[i-1][j-1] if i != 0 and j != 0
      end
    end
  end

  # @param {Integer} row1
  # @param {Integer} col1
  # @param {Integer} row2
  # @param {Integer} col2
  # @return {Integer}
  def sum_region(row1, col1, row2, col2)
    sum = @cache[row2][col2]
    sum -= @cache[row1-1][col2] if row1 != 0
    sum -= @cache[row2][col1-1] if col1 != 0
    sum += @cache[row1-1][col1-1] if row1 != 0 and col1 != 0
    sum
  end
end

# Your NumMatrix object will be instantiated and called as such:
# num_matrix = NumMatrix.new(matrix)
# num_matrix.sum_region(0, 1, 2, 3)
# num_matrix.sum_region(1, 2, 3, 4)
