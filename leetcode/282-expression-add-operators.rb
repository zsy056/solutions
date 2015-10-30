# @param {String} num
# @param {Integer} target
# @return {String[]}
def add_operators(num, target)
  $result = []
  (0...num.size).each do |i|
    prefix = num[0..i]
    prefix_i = prefix.to_i
    _add_operators num, i+1, target, prefix_i, prefix_i, prefix
    break if num[0] == '0'
  end
  $result
end


$result = []


def _add_operators(num, b, target, current, last, exp)
  if b == num.size and current == target
    $result.push exp
  elsif b < num.size
    postfix = num[b] == '0' ? [[0, num[b]]] : (b...num.size).map { |i| [num[b..i].to_i, num[b..i]] }
    # + 
    postfix.each do |pf|
      _add_operators num, b+pf[1].size, target, current + pf[0], pf[0], exp + '+' + pf[1]
    end
    # -
    postfix.each do |pf|
      _add_operators num, b+pf[1].size, target, current - pf[0], -pf[0], exp + '-' + pf[1]
    end
    # *
    postfix.each do |pf|
      _add_operators num, b+pf[1].size, target, current - last + last*pf[0], last*pf[0], exp + '*' + pf[1]
    end
  end
end

puts add_operators "105", 5
