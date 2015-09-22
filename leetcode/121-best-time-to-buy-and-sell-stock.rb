# @param {Integer[]} prices
# @return {Integer}
def max_profit(prices)
  max_profit = 0
  hold = nil
  prices.each do |p|
    if hold.nil? or p < hold
      hold = p
    end
    max_profit = [max_profit, p - hold].max
  end
  max_profit
end
