# @param {Integer[][]} dungeon
# @return {Integer}
def calculate_minimum_hp(dungeon)
  m, n = dungeon.size, dungeon[0].size
  mtx = (m+1).times.map { Array.new n+1, 0x7fffffff }
  mtx[m-1][n] = mtx[m][n-1] = 1
  (m-1).downto(0).each do |i|
    (n-1).downto(0).each do |j|
      mtx[i][j] = [1, [mtx[i+1][j], mtx[i][j+1]].min - dungeon[i][j]].max
    end
  end
  mtx[0][0]
end
