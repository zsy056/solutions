# @param {Integer[]} citations
# @return {Integer}
def h_index(citations)
  n = citations.size
  return 0 if n == 0
  sorted = citations.sort  
  h = 0
  while h < n
    break if sorted[n-1-h] < h + 1
    h += 1
  end
  h
end
