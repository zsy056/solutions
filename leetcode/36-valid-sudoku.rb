require 'set'

# @param {Character[][]} board
# @return {Boolean}
def is_valid_sudoku(board)
  board.each_with_index do |row, idx|
    return false unless is_valid_block row
    return false unless is_valid_block (0...9).map {|i| board[i][idx]}
    x = idx / 3
    y = idx % 3
    b3 = (0...9).map do |i|
      x1 = i / 3
      y1 = i % 3
      board[x*3 + x1][y*3 + y1]
    end
    return false unless is_valid_block b3
  end
  true
end

def is_valid_block(block)
  a  = Set.new
  block.each do |b|
    return false if a.include? b
    a.add b if b != '.'
  end
  true
end
