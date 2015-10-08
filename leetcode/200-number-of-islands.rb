# @param {Character[][]} grid
# @return {Integer}
def num_islands(grid)
  counter = 0
  (0...grid.size).each do |i|
    (0...grid[i].size).each do |j|
      if grid[i][j] == '1'
        flooding grid, i, j
        counter += 1
      end
    end
  end
  counter
end


def flooding(grid, i, j)
  if i >= 0 and i < grid.size and j >= 0 and j < grid[i].size and grid[i][j] == '1'
    grid[i][j] = '-'
    flooding grid, i+1, j
    flooding grid, i-1, j
    flooding grid, i, j+1
    flooding grid, i, j-1
  end
end
