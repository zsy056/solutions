# @param {Integer[]} nums
# @param {Integer} k
# @return {Integer}
def find_kth_largest(nums, k)
  kth nums, k, 0, nums.size 
end


def kth(nums, k, b, e)
  sidx = get_sentinel nums, b, e
  ob, oe = b, e
  e -= 1
  nums[sidx], nums[e] = nums[e], nums[sidx]
  e -= 1
  while b <= e
    if nums[b] >= nums[oe-1]
      b += 1
    else
      nums[b], nums[e] = nums[e], nums[b]
      e -= 1
    end
  end
  nums[b], nums[oe-1] = nums[oe-1], nums[b]
  if b + 1 == k
    nums[b]
  elsif b + 1 < k
    kth nums, k, b+1, oe
  else
    kth nums, k, ob, b
  end
end


def get_sentinel(nums, b, e)
  [b, e-1, (e-b)/2 + b].sort {|x, y| nums[x] <=> nums[y]}[1]
end
