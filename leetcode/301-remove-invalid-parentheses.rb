# @param {String} s
# @return {String[]}
def remove_invalid_parentheses(s)
  rextras = 0
  i = 0
  stk = 0
  while i < s.size
    if s[i] == '('
      stk += 1
    elsif s[i] == ')' and stk == 0
      rextras += 1
    elsif s[i] == ')'
      stk -= 1
    end
    i += 1
  end
  return [s] if stk == 0 and rextras == 0
  used = s.each_char.map { true }
  res = []
  combinations s, 0, stk, rextras, used, res, 0
  res
end


def is_valid(s)
  i = 0
  stk = 0
  while i < s.size
    if s[i] == '('
      stk += 1
    elsif s[i] == ')' and stk == 0
      return false
    elsif s[i] == ')'
      stk -= 1
    end
    i += 1
  end
  stk == 0
end


def combinations(src, nxt, lextras, rextras, used, res, stk)
  if lextras == 0 and rextras == 0 and stk == 0
    res.push src.each_char.select.with_index { |c, i| used[i] }.join ''
  elsif nxt >= src.size
    return
  elsif (src[nxt] == '(' or src[nxt] == ')') and (nxt == 0 or src[nxt-1] != src[nxt] or not used[nxt-1])
    used[nxt] = false
    nlextras = src[nxt] == '(' ? lextras - 1 : lextras
    nrextras = src[nxt] == ')' ? rextras - 1 : rextras
    combinations src, nxt+1, nlextras, nrextras, used, res, stk
    return if src[nxt] == ')' and stk == 0
    stk += 1 if src[nxt] == '('
    stk -= 1 if src[nxt] == ')'
    used[nxt] = true
    combinations src, nxt+1, lextras, rextras, used, res, stk
  else
    used[nxt] = false
    return if src[nxt] == ')' and stk == 0
    stk += 1 if src[nxt] == '('
    stk -= 1 if src[nxt] == ')' 
    used[nxt] = true
    combinations src, nxt+1, lextras, rextras, used, res, stk
  end
end
