# @param {String[]} strs
# @return {String}
def longest_common_prefix(strs)
  if strs.empty?
    ''
  else
    p = strs[0].split ''
    p = strs[1..-1].inject(p) {|cp, b| lcp cp, b.split('') }
    p.join('')
  end
end

def lcp(a, b)
  i = 0
  l = []
  while i < a.size and i < b.size
    if a[i] == b[i]
      l.push a[i]
    else
      break
    end
    i += 1
  end
  l
end
