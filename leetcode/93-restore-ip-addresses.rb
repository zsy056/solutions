# @param {String} s
# @return {String[]}
def restore_ip_addresses(s)
  _restore_ip(s, 4).map {|x| x.join '.'}
end


def _restore_ip(s, num)
  if num == 0 and s.empty?
    [[]]
  elsif num == 0 or s.empty?
    []
  else
    result = []
    (0..[2, s.size-1].min).each do |i|
      current = s[0..i].to_i
      if current >= 0 and current <= 255
        result += _restore_ip(s[i+1..-1], num - 1).map {|x| x.unshift current}
      end
      break if s[0] == '0'
    end
    result
  end
end

