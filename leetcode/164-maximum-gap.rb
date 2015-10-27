# @param {Integer[]} nums
# @return {Integer}
def maximum_gap(nums)
  return 0 if nums.size < 2  
  max_ele = nums.max
  min_ele = nums.min
  buckets = nums.map { [max_ele+1, min_ele-1] }
  bucket_size = (max_ele - min_ele) / nums.size + 1
  nums.each do |num|
    bucket_idx = (num - min_ele) / bucket_size
    old_min, old_max = buckets[bucket_idx]
    buckets[bucket_idx] = [[old_min, num].min, [old_max, num].max]
  end
  max_gap = 0
  buckets.select! { |b| b[0] != max_ele + 1 }
  buckets.each_with_index do |b, i|
    max_gap = [max_gap, b[1] - b[0]].max
    next if i == 0
    max_gap = [max_gap, b[0] - buckets[i-1][1]].max
  end
  max_gap
end

