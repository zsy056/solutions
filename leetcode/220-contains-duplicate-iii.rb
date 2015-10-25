# @param {Integer[]} nums
# @param {Integer} k
# @param {Integer} t
# @return {Boolean}
def contains_nearby_almost_duplicate(nums, k, t)
  return false if t < 0
  buckets = Hash.new
  nums.each_with_index do |num, idx|
    buckets.delete(t == 0 ? nums[idx-k-1] : nums[idx-k-1] / t) if idx > k
    bucket_idx = t == 0 ? num : num / t
    return true if buckets.include?(bucket_idx)
    return true if buckets.include?(bucket_idx+1) and (num - buckets[bucket_idx+1]).abs <= t
    return true if buckets.include?(bucket_idx-1) and (num - buckets[bucket_idx-1]).abs <= t
    buckets[bucket_idx] = num
  end
  false
end
