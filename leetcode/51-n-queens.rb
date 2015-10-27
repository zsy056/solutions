# @param {Integer} n
# @return {String[][]}
def solve_n_queens(n)
  $sols = []  
  cols = Array.new n.size, false
  x1 = Array.new n.size*2, false
  x2 = Array.new n.size*2, false
  board = n.times.map { '.' * n }
  n_queens n, 0, cols, x1, x2, board
  $sols
end


$sols = nil


def n_queens(n, i, cols, x1, x2, board)
  if n == i
    $sols.push copy board
    return
  end
  (0...n).each do |j|
    next if cols[j]
    x1_idx = i - j + n - 1
    next if x1[x1_idx]
    x2_idx = i + j
    next if x2[x2_idx]
    cols[j] = true
    x1[x1_idx] = true
    x2[x2_idx] = true
    board[i][j] = 'Q'
    n_queens n, i+1, cols, x1, x2, board
    board[i][j] = '.'
    cols[j] = false
    x1[x1_idx] = false
    x2[x2_idx] = false
  end
end


def copy(board)
  board.map { |row| row.dup }
end


#puts solve_n_queens(4).to_s
