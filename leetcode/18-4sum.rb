# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[][]}
def four_sum(nums, target)
  nums.sort!  
  res = []
  a = 0
  while a + 3 < nums.size and nums[a] * 4 <= target
    d = nums.size - 1
    while d >= a + 3 and nums[d] * 4 >= target
      b = a + 1
      c = d - 1
      while b < c
        sum = nums[a] + nums[b] + nums[c] + nums[d]
        if sum == target
          res.push [nums[a], nums[b], nums[c], nums[d]]
          ob = b
          while nums[ob] == nums[b]
            b += 1
          end
          oc = c
          while nums[oc] == nums[c]
            c -= 1
          end
        elsif sum < target
          ob = b
          while nums[ob] == nums[b]
            b += 1
          end
        else
          oc = c
          while nums[oc] == nums[c]
            c -= 1
          end
        end
      end
      od = d
      while nums[od] == nums[d]
        d -= 1
      end
    end
    oa = a
    while nums[oa] == nums[a]
      a += 1
    end
  end
  res
end
