# @param {Integer[]} ratings
# @return {Integer}
def candy(ratings)
  n = ratings.size
  candies = Array.new n, 1
  i = 0
  while i < n
    if (i == 0 and i < n-1 and ratings[i+1] >= ratings[i]) or (i == n-1 and i > 0 and ratings[i-1] >= ratings[i]) or (i > 0 and i < n-1 and ratings[i-1] >= ratings[i] and ratings[i+1] >= ratings[i]) or (i == 0 and i == n-1)
      j = 1
      while i - j >= 0 and ratings[i-j] > ratings[i-j+1]
        new_candies = candies[i-j+1] + 1
        candies[i-j] = [candies[i-j], new_candies].max
        j += 1
      end
      j = 1
      while i + j < n and ratings[i+j] > ratings[i+j-1]
        new_candies = candies[i+j-1] + 1
        candies[i+j] = [candies[i+j], new_candies].max
        j += 1
      end
      i += j
    else
      i += 1
    end
  end
  candies.inject(:+)
end
