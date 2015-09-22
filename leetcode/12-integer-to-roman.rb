LST = [[      1...4,    -1,  'I'],
       [      4...5,    -4, 'IV'],
       [      5...9,    -5,  'V'],
       [     9...10,    -9, 'IX'],
       [    10...40,   -10,  'X'],
       [    40...50,   -40, 'XL'],
       [    50...90,   -50,  'L'],
       [   90...100,   -90, 'XC'],
       [  100...400,  -100,  'C'],
       [  400...500,  -400, 'CD'],
       [  500...900,  -500,  'D'],
       [ 900...1000,  -900, 'CM'],
       [1000...4000, -1000,  'M']]

# @param {Integer} num
# @return {String}
def int_to_roman(num)
  res = ''
  return res if num <= 0
  LST.each do |x|
    if x[0].include? num
      res = x[2] + int_to_roman(num + x[1])
      break
    end
  end
  res
end
