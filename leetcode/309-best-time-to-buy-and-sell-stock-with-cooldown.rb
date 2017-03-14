# @param {Integer[]} prices
# @return {Integer}
def max_profit(prices)
  return 0 if prices.size == 0

  profits1 = prices.map { |x| 0 }
  profits2 = prices.map { |x| 0 }

  (1...prices.size).each do |i|
    if i >= 2
      profits1[i] = [profits2[i-2], profits1[i-1] + prices[i] - prices[i-1]].max
    else
      profits1[i] = [profits1[i-1] + prices[i] - prices[i-1], 0].max
    end
    profits2[i] = [profits1[i], profits2[i-1]].max
  end

  puts profits1.to_s
  puts profits2.to_s

  [0, profits2[-1]].max
end

puts(max_profit [1, 2, 4])
puts(max_profit [1, 2, 3, 0, 2])
