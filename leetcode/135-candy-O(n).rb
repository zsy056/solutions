# @param {Integer[]} ratings
# @return {Integer}
def candy(ratings)
  candies = Array.new ratings.size, 1  
  i = 1
  while i < ratings.size
    if ratings[i] > ratings[i-1]
      candies[i] = candies[i-1] + 1
    end
    i += 1
  end
  i = ratings.size - 2
  while i >= 0
    if ratings[i] > ratings[i+1]
      candies[i] = [candies[i], candies[i+1] + 1].max
    end
    i -= 1
  end
  candies.inject(:+)
end
