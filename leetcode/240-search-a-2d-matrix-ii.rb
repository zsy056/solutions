# @param {Integer[][]} matrix
# @param {Integer} target
# @return {Boolean}
def search_matrix(matrix, target)
  i = 0
  j = matrix[0].size - 1
  while i < matrix.size and j >= 0
    if matrix[i][j] == target
      return true
    elsif matrix[i][j] < target
      i += 1
    else
      j -= 1
    end
  end
  false
end
