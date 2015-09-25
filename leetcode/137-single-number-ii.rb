# @param {Integer[]} nums
# @return {Integer}
def single_number(nums)
  result = 0
  (0..31).each do |i|
    counter = 0
    nums.each do |x|
      counter += 1 if ((x >> i) & 1) == 1
    end
    result |= (1 << i) if counter % 3 != 0
  end
  [result].pack('L').unpack('l')[0]
end

