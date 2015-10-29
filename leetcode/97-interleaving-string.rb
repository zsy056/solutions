# @param {String} s1
# @param {String} s2
# @param {String} s3
# @return {Boolean}
def is_interleave(s1, s2, s3)
  return false if s1.size + s2.size != s3.size
  return false if (s1+s2).chars.sort != s3.chars.sort
  n, m = s1.size, s2.size
  mtx = (n+1).times.map { Array.new m+1, false }
  mtx[0][0] = true
  (1..n).each { |i| mtx[i][0] = mtx[i-1][0] && s1[i-1] == s3[i-1] }
  (1..m).each { |j| mtx[0][j] = mtx[0][j-1] && s2[j-1] == s3[j-1] }
  (1..n).each do |i|
    (1..m).each do |j|
      mtx[i][j] = ((mtx[i-1][j] && s1[i-1] == s3[i+j-1]) or (mtx[i][j-1] && s2[j-1] == s3[i+j-1]))
    end
  end
  mtx[n][m]
end
