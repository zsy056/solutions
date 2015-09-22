# @param {Integer} m
# @param {Integer} n
# @return {Integer}
def unique_paths(m, n)
  mtx = (m+1).times.map {|i| Array.new (n+1), 0}  
  mtx[1][1] = 1
  (1..m).each do |i|
    (1..n).each do |j|
      mtx[i][j] = mtx[i-1][j] + mtx[i][j-1] unless i == 1 and j == 1
    end
  end
  mtx[m][n]
end
