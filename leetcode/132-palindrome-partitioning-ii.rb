# @param {String} s
# @return {Integer}
def min_cut(s)
  n = s.size
  is_palindrome = (0...n).map { Array.new n, false }
  (1..n).each do |k|
    (0..n-k).each do |i|
      is_palindrome[i][i+k-1] = (k == 1 || ((is_palindrome[i+1][i+k-2] || i+1 == i+k-1) && s[i] == s[i+k-1]))
    end
  end
  min_cuts = (0...n).map { |x| x }
  (0...n).each do |i|
    if is_palindrome[0][i]
      min_cuts[i] = 0
    else
      (1..i).each do |j|
        min_cuts[i] = [min_cuts[i], min_cuts[j-1] + 1].min if is_palindrome[j][i]
      end
    end
  end
  min_cuts[n-1]
end
