# @param {String} s1
# @param {String} s2
# @return {Boolean}
def is_scramble(s1, s2)
  return true if s1 == s2
  return false if s1.nil? or s2.nil?
  return false if s1.size != s2.size
  n = s1.size
  mtx = (n+1).times.map { n.times.map { n.times.map { false } } } 
  (0...n).each do |i|
    (0...n).each do |j|
      mtx[1][i][j] = s1[i] == s2[j]
    end
  end
  (2..n).each do |len|
    (0..n-len).each do |i|
      (0..n-len).each do |j|
        (0..len-1).each do |k|
          mtx[len][i][j] ||= mtx[k][i][j] && mtx[len-k][i+k][j+k]
          mtx[len][i][j] ||= mtx[k][i][j+len-k] && mtx[len-k][i+k][j]
          break if mtx[len][i][j]
        end
      end
    end
  end
  mtx[n][0][0]
end
