# @param {Integer} n
# @return {Integer[]}
def gray_code(n)
  if n == 0
    [0]
  elsif n == 1
    [0, 1]
  else
    upper = gray_code(n - 1)
    lower = upper.reverse.map {|x| x | (1 << (n - 1))}
    upper + lower
  end
end
