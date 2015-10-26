# @param {Integer} n
# @return {Integer}
def total_n_queens(n)
  $counter = 0  
  row = Array.new n, false
  col = Array.new n, false
  x1 = Array.new n*2, false
  x2 = Array.new n*2, false
  queens n, 0, 0, 0, row, col, x1, x2
  $counter
end


$counter = 0


def queens(n, cn, bi, bj, row, col, x1, x2)
  if n == cn
    $counter += 1
    return
  end

  (bi...n).each do |i|
    next if row[i]
    (0...n).each do |j|
      next if col[j]
      x1_idx = i - j + n - 1
      next if x1[x1_idx]
      x2_idx = i + j
      next if x2[x2_idx]
      row[i] = true
      col[j] = true
      x1[x1_idx] = true
      x2[x2_idx] = true
      queens n, cn + 1, i + 1, j, row, col, x1, x2
      row[i] = false
      col[j] = false
      x1[x1_idx] = false
      x2[x2_idx] = false
    end
  end
end

