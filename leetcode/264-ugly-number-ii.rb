# @param {Integer} n
# @return {Integer}
def nth_ugly_number(n)
  a, b, c = [], [], [] 
  current = 1
  counter = 1
  while counter < n
    a.push current * 2
    b.push current * 3
    c.push current * 5
    current = [a[0], b[0], c[0]].min
    a = a[1..-1] if current == a[0]
    b = b[1..-1] if current == b[0]
    c = c[1..-1] if current == c[0]
    counter += 1
  end
  current
end
