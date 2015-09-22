# @param {Integer[][]} grid
# @return {Integer}
def min_path_sum(grid)
  m = grid.size
  n = grid[0].size
  mtx = (m+1).times.map {|x| Array.new(n+1)}
  mtx[1][1] = grid[0][0]
  (1..m).each do |i|
    (1..n).each do |j|
      unless mtx[i-1][j].nil?
        mtx[i][j] = mtx[i-1][j]
      end
      if mtx[i][j].nil? or ((not mtx[i][j-1].nil?) and mtx[i][j] > mtx[i][j-1])
        mtx[i][j] = mtx[i][j-1]
      end
      mtx[i][j] += grid[i-1][j-1] if i != 1 or j != 1
    end
  end
  mtx[m][n]
end
