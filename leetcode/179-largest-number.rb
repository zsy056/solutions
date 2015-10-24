# @param {Integer[]} nums
# @return {String}
def largest_number(nums)
  sorted = nums.map { |x| x.to_s }.sort { |a, b| compare a, b }.reverse
  begin_idx = sorted.index { |x| x != '0' }
  begin_idx = begin_idx.nil? ? -1 : begin_idx
  sorted[begin_idx..-1].join ''
end


def compare(a, b)
  i = 0
  while i < a.size and i < b.size
    res = a[i] <=> b[i]
    return res if res != 0
    i += 1
  end
  if a.size == b.size
    0
  elsif i == a.size
    compare a, b[i..-1]
  else
    compare a[i..-1], b
  end
end

