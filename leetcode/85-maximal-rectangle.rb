# @param {Character[][]} matrix
# @return {Integer}
def maximal_rectangle(matrix)
  return 0 if matrix.empty?
  i = 0
  max_a = 0
  height = Array.new matrix[0].size, 0
  while i < matrix.size
    matrix[i].each_with_index { |c, j| height[j] = c == '1' ? height[j]+1 : 0 }
    area = largest_rectangle_area height
    max_a = [max_a, area].max
    i += 1
  end
  max_a
end


def largest_rectangle_area(height)
  saved = []  # [[height, width]]  
  max_a = 0
  height.each do |h|
    max_a, width = collaps(saved, max_a) { saved[-1][0] >= h }
    saved.push [h, width + 1]
  end
  max_a, _ = collaps(saved, max_a) { true }
  max_a
end


def collaps(saved, max_a)
  min_height = nil
  width = 0
  while (not saved.empty?) and yield
    min_height = min_height.nil? ? saved[-1][0] : [min_height, saved[-1][0]].min
    width += saved[-1][1]
    max_a = [max_a, min_height * width].max
    saved.pop
  end
  [max_a, width]
end
