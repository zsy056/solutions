require 'set'

# @param {Character[][]} board
# @return {Void} Do not return anything, modify board in-place instead.
def solve_sudoku(board)
  n = board.size
  rows = n.times.map { Set.new }
  cols = n.times.map { Set.new }
  blocks = n.times.map { Set.new }
  to_fill = []
  (0...n).each do |i|
    a = i / 3
    (0...n).each do |j|
      if board[i][j] == '.'
        to_fill.push [i, j]
        next
      end
      rows[i].add board[i][j]
      cols[j].add board[i][j]
      b = j / 3
      blocks[a * 3 + b].add board[i][j]
    end
  end
  solve board, to_fill, 0, rows, cols, blocks
end


def solve(board, to_fill, nxt, rows, cols, blocks)
  return true if nxt == to_fill.size
  i, j = to_fill[nxt]
  a = i / 3
  b = j / 3
  ('1'..'9').each do |c|
    board[i][j] = c
    next if rows[i].include?(c) or cols[j].include?(c) or blocks[a*3+b].include?(c)
    rows[i].add c
    cols[j].add c
    blocks[3*a+b].add c
    return true if solve board, to_fill, nxt+1, rows, cols, blocks
    rows[i].delete c
    cols[j].delete c
    blocks[3*a+b].delete c
  end
  false
end
