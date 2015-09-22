# @param {Integer[][]} matrix
# @return {Void} Do not return anything, modify matrix in-place instead.
def rotate(matrix)
  n = matrix.size    
  (0...n/2).each do |i|
    (0...n/2).each do |j|
      trans matrix, i, j, n
    end
  end
  if n % 2 == 1
    (0...n/2).each do |i|
      trans matrix, (n/2), i, n
    end
  end
end

def trans(matrix, i, j, n)
  tmp = matrix[i][j]
  matrix[i][j] = matrix[n-1-j][i]
  matrix[n-1-j][i] = matrix[n-1-i][n-1-j]
  matrix[n-1-i][n-1-j] = matrix[j][n-1-i]
  matrix[j][n-1-i] = tmp
end
