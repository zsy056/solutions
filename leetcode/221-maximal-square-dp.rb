
# @param {Character[][]} matrix
# @return {Integer}
def maximal_square(matrix)
  max = 0
  (0...matrix.size).each do |i|
    (0...matrix[i].size).each do |j|
      next if matrix[i][j] == '0'
      a = i > 0 ? matrix[i-1][j] : '0'
      b = j > 0 ? matrix[i][j-1] : '0'
      c = (i > 0 and j > 0) ? matrix[i-1][j-1] : '0'
      matrix[i][j] = ([a.ord, b.ord, c.ord].min + 1).chr
      max = [max, matrix[i][j].ord - '0'.ord].max
    end
  end
  max * max
end

