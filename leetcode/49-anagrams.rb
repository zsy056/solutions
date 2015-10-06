# @param {String[]} strs
# @return {String[][]}
def group_anagrams(strs)
  groups = strs.inject(Hash.new) do |a, str|
    sig = get_sig str
    a[sig] = [] unless a.include? sig
    a[sig].push str
    a
  end
  groups.inject([]) do |a, x|
    a.push x[1].sort
    a
  end
end


def get_sig(str)
  str.each_char.inject(Hash.new) do |a, c|
    a[c] = 0 unless a.include? c
    a[c] += 1
    a
  end
end
