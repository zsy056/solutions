# @param {Character[][]} matrix
# @return {Integer}
def maximal_square(matrix)
  sizes = (0...matrix.size).map {Array.new matrix[0].size, 0}  
  max = 0
  (0...matrix.size).each do |i|
    (0...matrix[i].size).each do |j|
      next if matrix[i][j] == '0'
      res = fill matrix, sizes, i, j
      max = [max, res].max
    end
  end
  max * max
end


def fill(matrix, sizes, i, j)
  return if matrix[i][j] == '0'
  current = sizes[i][j]
  while current + i < matrix.size and current + j < matrix[0].size
    nxt = current
    p = i + nxt
    q = j
    while p < matrix.size and q < matrix[0].size and matrix[p][q] == '1' and q <= j + nxt
      q += 1
    end
    break if q <= j + nxt
    q = j + nxt
    p = i
    while p < matrix.size and q < matrix[0].size and matrix[p][q] == '1' and p <= i + nxt
      p += 1
    end
    break if p <= i + nxt
    current = nxt + 1
  end
  sizes[i][j] = current
  current
end

