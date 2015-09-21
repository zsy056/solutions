# The is_bad_version API is already defined for you.
# @param {Integer} version
# @return {boolean} whether the version is bad
# def is_bad_version(version):

# @param {Integer} n
# @return {Integer}
def first_bad_version(n)
  b = 1
  e = n
  while b < e
    mid = (e - b) / 2 + b
    if is_bad_version mid
      e = mid
    else
      b = mid + 1
    end
  end
  b
end
