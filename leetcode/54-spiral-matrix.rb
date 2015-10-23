# @param {Integer[][]} matrix
# @return {Integer[]}
def spiral_order(matrix)
  up_bound = -1
  low_bound = matrix.size
  return [] if low_bound == 0
  left_bound = -1
  right_bound = matrix[0].size
  i, j = 0, 0
  di, dj = 0, 1
  res = []
  while up_bound < low_bound - 1 and left_bound < right_bound - 1
    res.push matrix[i][j]
    if i + di == low_bound
      di = 0
      dj = -1
      right_bound -= 1
    elsif i + di == up_bound
      di = 0
      dj = 1
      left_bound += 1
    elsif j + dj == left_bound
      di = -1
      dj = 0
      low_bound -= 1
    elsif j + dj == right_bound
      di = 1
      dj = 0
      up_bound += 1
    end
    i += di
    j += dj
  end
  res
end
