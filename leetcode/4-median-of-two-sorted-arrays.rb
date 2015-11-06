# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}
def find_median_sorted_arrays(nums1, nums2)
  total = nums1.size + nums2.size
  if total & 1 == 1
    kth nums1, 0, nums1.size, nums2, 0, nums2.size, total/2
  else
    a = kth nums1, 0, nums1.size, nums2, 0, nums2.size, total/2
    b = kth nums1, 0, nums1.size, nums2, 0, nums2.size, total/2-1
    (a + b) / 2.to_f
  end
end

# k: 0 based
def kth(nums1, b1, e1, nums2, b2, e2, k)
  if b1 >= e1
    nums2[b2 + k]
  elsif b2 >= e2
    nums1[b1 + k]
  elsif k == 0
    [nums1[b1], nums2[b2]].min
  else
    mid1 = [k/2 + b1, e1-1].min
    mid2 = [b2 + k - 1 - (mid1 - b1), e2-1].min
    if nums1[mid1] == nums2[mid2]
      nums1[mid1]
    elsif nums1[mid1] < nums2[mid2]
      kth nums1, mid1+1, e1, nums2, b2, mid2+1, k - (mid1-b1) - 1
    else
      kth nums1, b1, mid1+1, nums2, mid2+1, e2, k - (mid2-b2) - 1
    end
  end
end

