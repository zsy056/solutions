# @param {String} s
# @return {String[][]}
def partition(s)
  _partition s, 0, s.size
end


def _partition(s, b, e)
  return [[]] if b >= e
  i = b + 1
  res = []
  while i <= e
    if is_palindrome s, b, i
      prefix = s[b...i]
      res += _partition(s, i, e).map {|p| p.unshift prefix}
    end
    i += 1
  end
  res
end


def is_palindrome(s, b, e)
  while b < e - 1
    return false if s[b] != s[e-1]
    b += 1
    e -= 1
  end
  true
end
