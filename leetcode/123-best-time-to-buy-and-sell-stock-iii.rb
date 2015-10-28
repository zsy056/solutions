# @param {Integer[]} prices
# @return {Integer}
def max_profit(prices)
  #    [current, next]
  s1 = [nil, 0] # open trans1
  s2 = [0, 0]   # close trans1
  s3 = [nil, 0] # open trans2
  s4 = [0, 0]   # close trans2
  current = 0
  nxt = 1
  prices.each do |price|
    s1[nxt] = s1[current].nil? ? -price : [s1[current], -price].max
    s2[nxt] = s1[current].nil? ? 0 : [s2[current], s1[current] + price].max
    s3[nxt] = s3[current].nil? ? -price : [s3[current], s2[current] - price].max
    s4[nxt] = s3[current].nil? ? 0 : [s4[current], s3[current] + price].max
    nxt, current = current, nxt
  end
  [s2[current], s4[current]].max
end

