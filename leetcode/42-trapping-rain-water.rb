# @param {Integer[]} height
# @return {Integer}
def trap(height)
  least_height = 0
  i = 0
  j = height.size - 1
  res = 0
  while i < j
    lower = nil
    if height[i] < height[j]
      lower = height[i]
      i += 1
    else
      lower = height[j]
      j -= 1
    end
    least_height = [least_height, lower].max
    res += least_height - lower
  end
  res
end
