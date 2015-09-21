# @param {String} s
# @param {Integer} num_rows
# @return {String}
def convert(s, num_rows)
  return s if num_rows == 1
  rows = num_rows.times.map {|x| ''}  
  i = 0
  j = 0
  state = 1
  while i < s.size
    rows[j] << s[i]
    i += 1
    if (j == num_rows - 1 and state == 1) || (j == 0 and state == -1)
      state *= -1
    end
    j += state
  end
  rows.join ''
end
