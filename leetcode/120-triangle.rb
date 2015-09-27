# @param {Integer[][]} triangle
# @return {Integer}
def minimum_total(triangle)
  n = triangle.size
  i = n - 1
  sums = triangle[i].map {|x| x}  
  i -= 1
  while i >= 0
    (0..i).each do |j|
      sums[j] = [sums[j], sums[j+1]].min + triangle[i][j]
    end
    i -= 1
  end
  sums[0]
end
