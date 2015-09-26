# @param {Integer[]} nums
# @return {Integer[][]}
def permute(nums)
  visited = Array.new nums.size, false  
  _permute nums, visited, nums.size
end


def _permute(nums, visited, n)
  if n == 0
    []
  elsif n == 1
    nums.select.with_index {|x, i| not visited[i]}.map {|x| [x]}
  else
    res = []
    nums.each_with_index do |x, i|
      unless visited[i]
        visited[i] = true
        partial = _permute(nums, visited, n - 1).map {|p| p.unshift x}
        visited[i] = false
        res += partial
      end
    end
    res
  end
end
