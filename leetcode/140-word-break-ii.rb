# @param {String} s
# @param {Set<String>} word_dict
# @return {String[]}
def word_break(s, word_dict)
  $result = []
  if word_dict.inject(false) { |m, x| m || s.end_with?(x) }
    longest = word_dict.inject(0) { |m, x| [m, x.size].max }
    _word_break s, 0, word_dict, [], longest
  end
  $result
end


$result = []


def _word_break(s, sb, word_dict, current, longest)
  if sb == s.size
    $result.push current.join ' '
  else
    i = sb
    while i < s.size and i-sb < longest
      word = s[sb..i]
      if word_dict.include? word
        current.push word
        _word_break s, i+1, word_dict, current, longest
        current.pop
      end
      i += 1
    end
  end
end
