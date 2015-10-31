# @param {String} s
# @param {Set<String>} word_dict
# @return {String[]}
def word_break(s, word_dict)
  $cache = Hash.new  
  if word_dict.inject(false) { |m, x| m || s.end_with?(x) }
    _word_break(s, word_dict).map { |x| x.join ' ' }
  else
    []
  end
end


$cache = nil


def _word_break(s, word_dict)
  if $cache.include? s.to_sym
    $cache[s.to_sym]
  else
    res = []
    (1..s.size).each do |i|
      word = s[0...i]
      if word_dict.include? word
        if i < s.size
          res.concat _word_break(s[i..-1], word_dict).map { |x| [word] + x }
        else
          res.push [word]
        end
      end
    end
    $cache[s.to_sym] = res
  end
end

