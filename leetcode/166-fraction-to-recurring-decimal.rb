# @param {Integer} numerator
# @param {Integer} denominator
# @return {String}
def fraction_to_decimal(numerator, denominator)
  is_neg = (numerator < 0) ^ (denominator < 0)
  numerator = numerator.abs
  denominator = denominator.abs
  int_part = numerator / denominator  
  fraction = []
  remains = [numerator % denominator]
  loop_begin = nil
  while remains[-1] != 0
    tmp = remains[-1] * 10
    fraction.push((tmp / denominator).to_s)
    new_remain = tmp % denominator
    loop_begin = remains.index new_remain
    break unless loop_begin.nil?
    remains.push new_remain
  end
  int_part = (is_neg and (int_part != 0 or not fraction.empty?)) ? '-' + int_part.to_s : int_part.to_s
  if fraction.empty?
    int_part
  elsif loop_begin.nil?
    int_part + '.' + fraction.join('')
  else
    int_part + '.' + fraction[0...loop_begin].join('') + '(' + fraction[loop_begin..-1].join('') + ')'
  end
end
