# @param {String} secret
# @param {String} guess
# @return {String}
def get_hint(secret, guess)
  chars = secret.chars.group_by { |x| x }.map { |k, v| [k, v.size] }.to_h
  as = 0
  valid = secret.chars.map { true }
  guess.chars.each_with_index do |c, i|
    if c == secret[i]
      chars[c] -= 1
      as += 1
      valid[i] = false
    end
  end
  bs = 0
  guess.chars.each_with_index do |c, i|
    next unless valid[i]
    if chars.include? c and chars[c] > 0
      bs += 1
      chars[c] -= 1
    end
  end
  "#{as}A#{bs}B"
end
