require 'set'

# @param {Character[][]} board
# @return {Void} Do not return anything, modify board in-place instead.
def solve(board)
  return if board.empty?
  num = 0
  (0...board.size).each do |i|
    (0...board[i].size).each do |j|
      next if board[i][j] != 'O'
      flooding board, i, j, num
      num += 1
    end
  end

  to_remain = Set.new
  (0...board.size).each do |i|
    to_remain.add board[i][0] if board[i][0] != 'X'
    to_remain.add board[i][-1] if board[i][-1] != 'X'
  end
  (0...board[0].size).each do |i|
    to_remain.add board[0][i] if board[0][i] != 'X'
    to_remain.add board[-1][i] if board[-1][i] != 'X'
  end

  (0...board.size).each do |i|
    (0...board[i].size).each do |j|
      next if board[i][j] == 'X'
      board[i][j] = to_remain.include?(board[i][j]) ? 'O' : 'X'
    end
  end
end


def flooding(board, i, j, num)
  q = [[i, j]]
  while not q.empty?
    i, j = q.pop
    next if i < 0 or i >= board.size or j < 0 or j >= board[i].size or board[i][j] != 'O'
    board[i][j] = num
    q.push [i+1, j]
    q.push [i, j+1]
    q.push [i, j-1]
    q.push [i-1, j]
  end
end
