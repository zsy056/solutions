# @param {String} s
# @return {Integer}
def title_to_number(s)
  aord = 'A'.ord
  s.split('').inject(0) do |num, c|
    digit = c.ord - aord + 1;
    num = num * 26 + digit
  end
end
