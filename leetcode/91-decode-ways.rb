# @param {String} s
# @return {Integer}
def num_decodings(s)
  counters = Array.new s.size, 0
  s.each_char.with_index do |c, i|
    if c != '0'
      counters[i] = i == 0 ? 1 : counters[i-1]
      counters[i] += (i == 1 ? 1 : counters[i-2]) if i >= 1 and s[i-1..i].to_i <= 26 and s[i-1] != '0'
    elsif i == 0 or s[i-1] > '2' or s[i-1] < '1'
      return 0
    else
      counters[i] = i == 1 ? 1 : counters[i-2]
    end
  end
  counters.empty? ? 0 : counters[-1]
end
