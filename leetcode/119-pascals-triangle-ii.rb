# @param {Integer} row_index
# @return {Integer[]}
def get_row(row_index)
  row = Array.new row_index + 1, 0  
  (0..row_index/2).each do |i|
    row[i] = C(row_index, i)
  end
  (row_index/2+1..row_index).each do |i|
    row[i] = row[row_index - i]
  end
  row
end

def C(a, b)
  fact(a) / fact(a - b) / fact(b)
end

$facts = [1, 1]

def fact(n)
  while $facts.size <= n
    $facts.push $facts[-1] * $facts.size
  end
  $facts[n]
end
