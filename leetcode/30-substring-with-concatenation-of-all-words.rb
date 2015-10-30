# @param {String} s
# @param {String[]} words
# @return {Integer[]}
def find_substring(s, words)
  m = words[0].size
  n = words.size
  schars = s.chars
  seqs = (0...m).map { |b| schars[b..-1].each_slice(m).map { |x| x.join.hash } }
  words_signature = words.map { |x| x.hash }.inject(:+)
  res = []
  seqs.each_with_index do |seq, i|
    signature = 0
    seq.each_with_index do |h, j|
      if j < n
        signature += h
      else
        signature -= seq[j-n]
        signature += h
      end
      res.push((j-n+1)*m+i) if signature == words_signature
    end
  end
  res
end

