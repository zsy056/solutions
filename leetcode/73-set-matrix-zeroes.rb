# @param {Integer[][]} matrix
# @return {Void} Do not return anything, modify matrix in-place instead.
def set_zeroes(matrix)
  m = matrix.size
  n = matrix[0].size
  (0...m).each do |i|
    (0...n).each do |j|
      set_nil(matrix, i, j, m, n) if matrix[i][j] == 0
    end
  end
  (0...m).each do |i|
    (0...n).each do |j|
      matrix[i][j] = 0 if matrix[i][j].nil?
    end
  end
end


def set_nil(matrix, i, j, m, n)
  (0...m).each do |x|
    matrix[x][j] = nil if matrix[x][j] != 0
  end
  (0...n).each do |x|
    matrix[i][x] = nil if matrix[i][x] != 0
  end
end
