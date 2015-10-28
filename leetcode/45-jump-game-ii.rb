# @param {Integer[]} nums
# @return {Integer}
def jump(nums)
  return 0 if nums.size == 1
  reachable = [[0, 0]] # [[reach, step]]
  step = 0
  nums.each_with_index do |num, i|
    if (not reachable.empty?) and reachable[0][0] < i
      old = reachable.shift
      step = old[1] + 1
    end
    new_reach = num + i
    if new_reach >= nums.size - 1
      step += 1
      break
    end
    if reachable.empty?
      reachable = [[new_reach, step + 1]]
    elsif reachable[-1][1] == step + 1 and reachable[-1][0] < new_reach
      reachable[-1][0] = new_reach
    elsif new_reach > reachable[-1][0]
      reachable.push [new_reach, step + 1]
    end
  end
  step
end

#puts jump [2, 3, 1, 1, 4]
#puts jump [1, 2]
