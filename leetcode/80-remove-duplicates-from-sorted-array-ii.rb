# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)
  nxt = 0  
  len = 0
  while nxt < nums.size
    nums[len] = nums[nxt]
    len += 1
    if nxt == nums.size - 1 or nums[nxt] != nums[nxt+1]
      nxt += 1
    else
      while nxt < nums.size - 1 and nums[nxt+1] == nums[nxt]
        nxt += 1
      end
    end
  end
  len
end
