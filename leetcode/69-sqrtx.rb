# @param {Integer} x
# @return {Integer}
def my_sqrt(x)
  b = 0
  e = x
  while b < e
    mid = (e - b) / 2 + b
    midmid = mid ** 2
    if midmid == x or (midmid < x and (mid+1) ** 2 > x)
      b = mid
      break
    elsif midmid < x
      b = mid + 1
    else
      e = mid - 1
    end
  end
  b
end
