# @param {Integer[]} nums
# @return {Integer[][]}
def three_sum(nums)
  nums.sort!  
  i = 0
  res = []
  while i < nums.size - 2
    j = i + 1
    k = nums.size - 1
    while j < k
      sum = nums[i] + nums[j] + nums[k]
      if sum > 0
        k -= 1
        while nums[k] == nums[k+1]
          k -= 1
        end
      elsif sum < 0
        j += 1
        while nums[j] == nums[j-1]
          j += 1
        end
      else
        res.push [nums[i], nums[j], nums[k]]
        k -= 1
        j += 1
        while nums[k] == nums[k+1]
          k -= 1
        end
        while nums[j] == nums[j-1]
          j += 1
        end
      end
    end
    i += 1
    while nums[i] == nums[i-1]
      i += 1
    end
  end
  res
end
