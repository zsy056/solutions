# @param {String} s
# @return {Boolean}
def is_valid(s)
  prev = []
  s.split('').each do |c|
    if MATCH.include? c
      return false if prev.empty?
      return false if prev[-1] != MATCH[c]
      prev.pop
    else
      prev.push c
    end
  end
  prev.empty?
end

MATCH = {'}' => '{', ']' => '[', ')' => '('}
