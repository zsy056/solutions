# @param {String} s
# @param {String} t
# @return {String}
def min_window(s, t)
  i, j = 0, 0  
  target = t.chars.group_by { |x| x }.map { |k, v| [k, v.size] }.to_h
  counts = t.chars.map { |c| [c, 0] }.to_h
  ti, tj = 0, s.size
  while j < s.size and not is_valid counts, target
      counts[s[j]] += 1 if counts.include? s[j]
      j += 1
  end
  while i < j
    if counts.include? s[i]
      if counts[s[i]] == target[s[i]]
        break
      else
        counts[s[i]] -= 1
      end
    end
    i += 1
  end
  ti, tj = i, j if tj - ti > j - i
  while j < s.size
    while j < s.size
      counts[s[j]] += 1 if counts.include? s[j]
      j += 1
      break if s[i] == s[j-1]
    end
    while i < j
      if counts.include? s[i]
        if counts[s[i]] == target[s[i]]
          break
        else
          counts[s[i]] -= 1
        end
      end
      i += 1
    end
    ti, tj = i, j if tj - ti > j - i
  end
  is_valid(counts, target) ? s[ti...tj] : ''
end


def is_valid(h, target)
  h.inject(true) { |m, x| m and x[1] >= target[x[0]] }
end


puts min_window "ab", "a"
