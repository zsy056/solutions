# @param {String} word1
# @param {String} word2
# @return {Integer}
def min_distance(word1, word2)
  min_dists = (word1.size+1).times.map { Array.new word2.size + 1, 0 }  
  word1.size.times { |i| min_dists[i+1][0] = i+1 }
  word2.size.times { |j| min_dists[0][j+1] = j+1 }
  word1.each_char.with_index do |c, i|
    word2.each_char.with_index do |d, j|
      if c == d
        min_dists[i+1][j+1] = [min_dists[i][j], min_dists[i][j+1] + 1, min_dists[i+1][j] + 1].min
      else
        min_dists[i+1][j+1] = [min_dists[i][j] + 1, min_dists[i][j+1] + 1, min_dists[i+1][j] + 1].min
      end
    end
  end
  min_dists[word1.size][word2.size]
end
