# @param {String[]} strs
# @return {String}
def longest_common_prefix(strs)
  if strs.empty?
    ''
  else
    p = strs[0]
    strs[1..-1].inject(p) {|cp, b| lcp cp, b }
  end
end

def lcp(a, b)
  i = 0
  while i < a.size and i < b.size
    if a[i] != b[i]
      break
    end
    i += 1
  end
  a[0...i]
end
