# @param {Integer[][]} buildings
# @return {Integer[][]}
def get_skyline(buildings)
  buildings.sort! { |a, b| a[0] <=> b[0] }  
  heap = Heap.new { |a, b| -(a[0] <=> b[0]) }
  res = []
  buildings.each do |building|
    bidx, eidx, height = building
    while not heap.empty? and heap.top[1] < bidx
      _, idx = heap.pop
      while not heap.empty? and heap.top[1] <= idx
        heap.pop
      end
      h = heap.empty? ? 0 : heap.top[0]
      res.push [idx, h] if res.empty? or res[-1][1] != h
    end
    heap.add [height, eidx]
    current_height = heap.empty? ? 0 : heap.top[0]
    if res.empty? or (res[-1][1] != current_height and res[-1][0] != bidx)
      res.push [bidx, current_height] 
    elsif res[-1][0] == bidx
      res[-1][1] = [res[-1][1], current_height].max
    end
  end
  while not heap.empty?
    _, idx = heap.pop
    while not heap.empty? and heap.top[1] <= idx
      heap.pop
    end
    h = heap.empty? ? 0 : heap.top[0]
    res.push [idx, h] if res.empty? or (res[-1][1] != h and res[-1][0] < idx)
  end
  res
end


class Heap

  # comparer: >0 down, 0 eq, <0 up
  def initialize(&comparer)
    @arr = []
    @comp = comparer
  end

  def empty?
    @arr.empty?
  end

  def add(x)
    @arr.push x
    i = @arr.size - 1
    while i > 0 and @comp.call(@arr[(i-1)/2], @arr[i]) > 0
      @arr[(i-1)/2], @arr[i] = @arr[i], @arr[(i-1)/2]
      i = (i-1)/2
    end
  end

  def top
    @arr[0]
  end

  def pop
    @arr[0], @arr[-1] = @arr[-1], @arr[0]
    tmp = @arr.pop
    i = 0
    while true
      if i*2 + 1 < @arr.size
        nxt_i = (i*2 + 2 >= @arr.size or @comp.call(@arr[i*2+1], @arr[i*2+2]) < 0) ? i*2+1 : i*2+2
        if @comp.call(@arr[i], @arr[nxt_i]) > 0
          @arr[i], @arr[nxt_i] = @arr[nxt_i], @arr[i]
          i = nxt_i
        else
          break
        end
      else
        break
      end
    end
    tmp
  end

end

