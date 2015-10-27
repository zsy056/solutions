# @param {String} s
# @param {String} t
# @return {Integer}
def num_distinct(s, t)
  counts = Array.new t.size, 0
  t.reverse!
  s.each_char do |c|
    t.each_char.with_index do |d, i|
      counts[i] += i == t.size-1 ? 1 : counts[i+1] if c == d
    end
  end
  counts[0].nil? ? 0 : counts[0]
end
