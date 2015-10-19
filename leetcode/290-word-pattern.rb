# @param {String} pattern
# @param {String} str
# @return {Boolean}
def word_pattern(pattern, str)
  words = str.split ' '  
  return false if words.size != pattern.size
  mappings1 = Hash.new
  mappings2 = Hash.new
  pattern.each_char.with_index do |c, i|
    if mappings1.include? c
      return false if mappings1[c] != words[i]
    else
      mappings1[c] = words[i]
    end
    if mappings2.include? words[i]
      return false if mappings2[words[i]] != c
    else
      mappings2[words[i]] = c
    end
  end
  true
end
