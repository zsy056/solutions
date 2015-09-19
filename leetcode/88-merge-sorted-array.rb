# @param {Integer[]} nums1
# @param {Integer} m
# @param {Integer[]} nums2
# @param {Integer} n
# @return {Void} Do not return anything, modify nums1 in-place instead.
def merge(nums1, m, nums2, n)
  nt = m + n
  current = nt - 1
  i = m - 1
  j = n - 1
  while current >= 0
    if i >= 0 and (j < 0 or nums1[i] >= nums2[j])
      nums1[current] = nums1[i]
      i -= 1
    elsif j >= 0
      nums1[current] = nums2[j]
      j -= 1
    end
    current -= 1
  end
end
