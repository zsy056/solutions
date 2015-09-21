# @param {Integer[]} prices
# @return {Integer}
def max_profit(prices)
  return 0 if prices.empty?
  deltas = Array.new(prices.size - 1)  
  prices.each_with_index do |p, idx|
    deltas[idx] = prices[idx+1] - p if idx != prices.size - 1
  end
  deltas.select {|x| x > 0}.inject(0) {|s, n| s + n}
end
