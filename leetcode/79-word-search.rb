# @param {Character[][]} board
# @param {String} word
# @return {Boolean}
def exist(board, word)
  return false if board.empty?
  visited = (0...board.size).map {Array.new board[0].size, false}  
  (0...board.size).each do |i|
    (0...board[i].size).each do |j|
      res = search(board, visited, word, i, j)
      return true if res
    end
  end
  false
end


def search(board, visited, word, i, j)
  return true if word.empty?
  return false if i < 0 or i >= board.size or j < 0 or j >= board[i].size or visited[i][j] or board[i][j] != word[0]
  visited[i][j] = true
  rest = word[1..-1]
  res = search(board, visited, rest, i+1, j) || search(board, visited, rest, i, j+1) || search(board, visited, rest, i-1, j) || search(board, visited, rest, i, j-1)
  visited[i][j] = false
  res
end
