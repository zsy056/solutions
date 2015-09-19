# @param {Integer} num
# @return {Boolean}
def is_ugly(num)
  if num == 1
    true
  elsif num <= 0
    false
  else
    (num % 2 == 0 and is_ugly(num / 2)) or (num % 3 == 0 and is_ugly(num / 3)) or (num % 5 == 0 and is_ugly(num / 5))
  end
end
