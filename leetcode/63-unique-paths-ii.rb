# @param {Integer[][]} obstacle_grid
# @return {Integer}
def unique_paths_with_obstacles(obstacle_grid)
  m = obstacle_grid.size
  n = obstacle_grid[0].size
  return 0 if obstacle_grid[m-1][n-1] == 1 or obstacle_grid[0][0] == 1
  mtx = (0..m).map {Array.new(n+1, 0)}  
  mtx[1][1] = 1
  (1..m).each do |i|
    (1..n).each do |j|
      mtx[i][j] = mtx[i-1][j] + mtx[i][j-1] if obstacle_grid[i-1][j-1] != 1 and (i != 1 or j != 1)
    end
  end
  mtx[m][n]
end
