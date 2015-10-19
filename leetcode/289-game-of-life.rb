# @param {Integer[][]} board
# @return {Void} Do not return anything, modify board in-place instead.
def game_of_life(board)
  m = board.size
  n = board[0].size
  m.times.each do |i|
    n.times.each do |j|
      neighbors = count_neighbors(board, i, j, m, n)
      if neighbors < 2 and board[i][j] > 0
        board[i][j] = 2
      elsif neighbors > 3 and board[i][j] > 0
        board[i][j] = 2
      elsif neighbors == 3 and board[i][j] <= 0
        board[i][j] = -1
      end
    end
  end

  m.times.each do |i|
    n.times.each do |j|
      if board[i][j] == 2
        board[i][j] = 0
      elsif board[i][j] == -1
        board[i][j] = 1
      end
    end
  end
end


def count_neighbors(board, i, j, m, n)
  counter = 0
  (i-1..i+1).each do |ki|
    (j-1..j+1).each do |kj|
      counter += 1 if ki >= 0 and ki < m and kj >= 0 and kj < n and (ki != i or kj != j) and board[ki][kj] > 0
    end
  end
  counter
end
