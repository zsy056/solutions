# @param {String} s
# @return {String[]}
def find_repeated_dna_sequences(s)
  res = []  
  mask = 0xfffff
  current = s[0..9].each_char.inject(0) {|m, x| m = (m << 2) | $bits[x]}
  sets = {current => 0}
  i = 10
  while i < s.size
    # Need to mask the `current` every time or `current` will be really big and slow
    current = mask & (current << 2) | $bits[s[i]]
    stat = sets[mask & current]
    if stat == 0
      res.push s[i-9..i]
      sets[mask & current] = 1
    elsif stat.nil?
      sets[mask & current] = 0
    end
    i += 1
  end
  res
end

$bits = {'A' => 0, 'C' => 1, 'G' => 2, 'T' => 3}
