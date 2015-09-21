# @param {String} s
# @return {Boolean}
def is_palindrome(s)
  _is_palindrome s.gsub(/[^0-9a-zA-Z]/, '')
end

def _is_palindrome(s)
  i = 0
  n = s.length
  s1 = s.downcase
  while i < n/2
    return false if s1[i] != s1[n-1-i]
    i += 1
  end
  true
end
