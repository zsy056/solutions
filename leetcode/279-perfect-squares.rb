# @param {Integer} n
# @return {Integer}
def num_squares(n)
  while $num.size <= n
    nxt = $num.size
    val = nxt
    sq = Math.sqrt(nxt).to_i
    if sq ** 2 == nxt
      val = 1
    else
      while sq >= 1
        val = [val, $num[nxt - sq ** 2]].min
        sq -= 1
      end
      val += 1
    end
    $num << val
  end
  $num[n]
end

$num = [0, 1]
