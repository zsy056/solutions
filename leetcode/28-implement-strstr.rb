# @param {String} haystack
# @param {String} needle
# @return {Integer}
def str_str(haystack, needle)
  n = needle.size
  k = haystack.size
  nxt = get_next needle 
  m = 0
  i = 0
  while m + n <= k and i < n
    while m + n <= k and haystack[m + i] != needle[i]
      m = m + i - nxt[i]
      i = [nxt[i], 0].max
    end
    while m + n <= k and i < n and haystack[m + i] == needle[i]
      i += 1
    end
  end
  i == n ? m : -1
end

def get_next(needle)
  n = needle.size
  return [] if n == 0
  nxt = Array.new [n, 2].max
  nxt[0] = -1
  nxt[1] = 0
  j = 2
  while j < n
    while j < n and needle[j-1] == needle[nxt[j-1]]
      nxt[j] = nxt[j-1] + 1
      j += 1
    end
    nxt[j] = 0
    j += 1
  end
  nxt
end

