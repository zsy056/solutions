# @param {Integer[]} nums
# @return {Integer[][]}
def subsets_with_dup(nums)
  visited = Array.new nums.size, false  
  nums = nums.sort
  (0..nums.size).flat_map {|k| subsets nums, visited, 0, k}
end


def subsets(nums, visited, b, k)
  if k == 0 || b >= nums.size
    [[]]
  else
    i = b
    res = []
    while i <= nums.size - k
      if (not visited[i]) and (i == 0 or nums[i] != nums[i-1] or visited[i-1])
        visited[i] = true
        ans = subsets(nums, visited, i+1, k-1).map {|x| x.unshift nums[i]}
        res += ans
        visited[i] = false
      end
      i += 1
    end
    res
  end
end
