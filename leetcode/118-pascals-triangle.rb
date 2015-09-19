# @param {Integer} num_rows
# @return {Integer[][]}
def generate(num_rows)
  total = (1..num_rows).map {|x| Array.new x } 
  total.each_with_index do |row, idx|
    row[0] = 1
    row[-1] = 1
    next if idx == 0
    (1..row.size-2).each do |i|
      row[i] = total[idx-1][i-1] + total[idx-1][i]
    end
  end
  total
end
