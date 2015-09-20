# @param {String} s
# @return {Integer}
def length_of_last_word(s)
  a = s.split(/\s/)
  a.empty? ? 0 : a[-1].size
end
