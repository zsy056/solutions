# @param {String} s
# @param {String} t
# @return {Boolean}
def is_isomorphic(s, t)
  _is_isomorphic(s, t) and _is_isomorphic(t, s)
end

def _is_isomorphic(s, t)
  i = 0  
  mapping = Hash.new
  while i < s.length
    if mapping.include? s[i]
      return false unless mapping[s[i]] == t[i]
    else
      mapping[s[i]] = t[i]
    end
    i += 1
  end
  true
end
