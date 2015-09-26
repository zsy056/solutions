# @param {Integer} k
# @param {Integer} n
# @return {Integer[][]}
def combination_sum3(k, n)
  nums = (1..9).map {|x| x}  
  visited = (1..9).map {false}
  solve nums, visited, n, k, 0
end


def solve(nums, visited, n, k, nxt)
  i = nxt
  if n == 0 and k == 0
    [[]]
  elsif k == 0 or n == 0
    []
  else
    ans = []
    while i < nums.size and nums[i] <= n
      unless visited[i]
        visited[i] = true
        coms = solve(nums, visited, n - nums[i], k - 1, i+1).map {|com| com.unshift nums[i]}
        visited[i] = false
        ans += coms
      end
      i += 1
    end
    ans
  end
end
