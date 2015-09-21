# @param {Integer[]} nums
# @param {Integer} k
# @return {Void} Do not return anything, modify nums in-place instead.
def rotate(nums, k)
  n = nums.size
  k = k % n
  return if k == 0
  nxt = k
  cnt = 0
  num = nums[0]
  seg = k
  while cnt < n
    tmp = nums[nxt]
    nums[nxt] = num
    cnt += 1
    nxt = (nxt + k) % n
    num = tmp
    if nxt == seg
      nxt += 1
      seg = nxt
      num = nums[(nxt + n - k) % n]
    end
  end
end
