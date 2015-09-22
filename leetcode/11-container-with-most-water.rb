# @param {Integer[]} height
# @return {Integer}
def max_area(height)
  b = 0
  e = height.size - 1
  v = [height[b], height[e]].min * (e - b)
  while b < e
    if height[b] < height[e]
      i = b + 1
      while i < e and height[b] >= height[i]
        i += 1
      end
      b = i
      v = [v, [height[b], height[e]].min * (e - b)].max
    else
      i = e - 1
      while i > b and height[e] >= height[i]
        i -= 1
      end
      e = i
      v = [v, [height[b], height[e]].min * (e - b)].max
    end
  end
  v
end
