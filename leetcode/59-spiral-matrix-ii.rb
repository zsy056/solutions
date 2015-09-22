# @param {Integer} n
# @return {Integer[][]}
def generate_matrix(n)
  mtx = n.times.map {Array.new n}  
  x, i, j, istate, jstate = 1, 0, 0, 0, 1
  while x <= n*n
    if mtx[i][j].nil?
      mtx[i][j] = x
    end
    if istate == 1 and (i+1 == n or (not mtx[i+1][j].nil?))
      istate = 0
      jstate = -1
    elsif istate == -1 and (i == 0 or (not mtx[i-1][j].nil?))
      istate = 0
      jstate = 1
    elsif jstate == 1 and (j+1 == n or (not mtx[i][j+1].nil?))
      istate = 1
      jstate = 0
    elsif jstate == -1 and (j == 0 or (not mtx[i][j-1].nil?))
      istate = -1
      jstate = 0
    end
    i += istate
    j += jstate
    x += 1
  end
  mtx
end
