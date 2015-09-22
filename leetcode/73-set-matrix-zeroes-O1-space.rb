# @param {Integer[][]} matrix
# @return {Void} Do not return anything, modify matrix in-place instead.
def set_zeroes(matrix)
  m = matrix.size
  n = matrix[0].size
  col, row = -1, -1
  (0...m).each do |i|
    (0...n).each do |j|
      if matrix[i][j] == 0
        row = i
        col = j
        break
      end
    end
    break if row != -1
  end
  return if row == -1
  (0...m).each do |i|
    (0...n).each do |j|
      if matrix[i][j] == 0
        matrix[i][col] = 0
        matrix[row][j] = 0
      end
    end
  end
  (0...m).each do |i|
    if matrix[i][col] == 0 and i != row
      (0...n).each {|j| matrix[i][j] = 0}
    end
  end
  (0...n).each do |j|
    if matrix[row][j] == 0 and j != col
      (0...m).each {|i| matrix[i][j] = 0}
    end
  end
  (0...m).each {|i| matrix[i][col] = 0}
  (0...n).each {|j| matrix[row][j] = 0}
end

