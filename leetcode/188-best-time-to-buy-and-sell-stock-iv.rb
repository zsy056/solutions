# @param {Integer} k
# @param {Integer[]} prices
# @return {Integer}
def max_profit(k, prices)
  profit = 0
  if k >= prices.size / 2  
    i = 1
    while i < prices.size
      profit += [prices[i] - prices[i-1], 0].max
      i += 1
    end
  elsif k > 0
    mtx = 2.times.map { k.times.map { [-9999999, 0] } }
    current, nxt = 0, 1
    prices.each do |p|
      (0...k).each do |j|
        mtx[nxt][j][0] = [mtx[current][j][0], (j == 0 ? 0 : mtx[current][j-1][1])-p].max
        mtx[nxt][j][1] = [mtx[current][j][1], mtx[current][j][0] + p].max
      end
      current, nxt = nxt, current
    end
    profit = mtx[current].map { |x| x[1] }.max
  end
  profit
end
