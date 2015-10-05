# @param {Integer[]} gas
# @param {Integer[]} cost
# @return {Integer}
def can_complete_circuit(gas, cost)
  i = 0
  delta = gas.map.with_index {|x, j| gas[j] - cost[j]}
  while i < gas.size
    idx = _can_complete delta, i
    if idx < 0 and -idx <= i
      break
    elsif idx < 0
      i = -idx
    else
      return idx
    end
  end
  -1
end


def _can_complete(delta, b)
  current = 0
  i = b
  while true
    current += delta[i]
    return -i-1 if current < 0
    i = (i + 1) % delta.size
    break if i == b
  end
  b
end
