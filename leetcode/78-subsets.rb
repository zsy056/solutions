# @param {Integer[]} nums
# @return {Integer[][]}
def subsets(nums)
  visited = Array.new nums.size, false
  nums = nums.sort
  (0..nums.size).flat_map {|k| _subsets nums, visited, k, 0}
end

def _subsets(nums, visited, k, b)
  if k == 0
    [[]]
  else
    ans = []
    while b <= nums.size - k
      unless visited[b]
        visited[b] = true
        tail = _subsets(nums, visited, k-1, b+1).map {|x| x.unshift nums[b]}
        ans += tail
        visited[b] = false
      end
      b += 1
    end
    ans
  end
end
