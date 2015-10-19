# @param {String} s
# @param {Set<String>} word_dict
# @return {Boolean}
def word_break(s, word_dict)
  cache = Hash.new
  _word_break s, word_dict, cache
end


def _word_break(s, word_dict, cache)
  return cache[s] if cache.include? s
  s.size.downto(1).each do |i|
    return cache[s] = true if word_dict.include?(s[0...i]) and (i == s.size or _word_break(s[i..-1], word_dict, cache))
  end
  cache[s] = false
end
