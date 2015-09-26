# @param {Integer[][]} matrix
# @param {Integer} target
# @return {Boolean}
def search_matrix(matrix, target)
  row = 0
  b = 0
  e = matrix.size - 1
  while b < e
    mid = (e - b) / 2 + b
    if matrix[mid][0] == target
      return true
    elsif matrix[mid][0] > target
      e = mid - 1
    elsif matrix[mid][-1] < target
      b = mid + 1
    else
      b = mid
      break
    end
  end
  row = b

  b = 0
  e = matrix[row].size - 1
  while b < e
    mid = (e - b) / 2 + b
    if matrix[row][mid] == target
      return true
    elsif matrix[row][mid] < target
      b = mid + 1
    else
      e = mid - 1
    end
  end
  matrix[row][b] == target
end
