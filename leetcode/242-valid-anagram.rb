# @param {String} s
# @param {String} t
# @return {Boolean}
def is_anagram(s, t)
  get_h(s) == get_h(t)
end

def get_h(s)
  s.split('').inject(Hash.new) do |h, c|
    h[c] = 0 unless h.include? c
    h[c] += 1
    h
  end
end
