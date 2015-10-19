class MedianFinder

  def initialize
    @size = 0
    @h1 = Heap.new :>
    @h2 = Heap.new :<
    @mid = nil
  end

  # @param {integer} word
  # @return {void}
  # Adds a num into the data structure.
  def add_num(num)
    if @mid.nil?
      left = @h1.top
      right = @h2.top
      if (not left.nil?) and left > num
        @h1.pop
        @h1.push num
        @mid = left
      elsif (not right.nil?) and right < num
        @h2.pop
        @h2.push num
        @mid = right
      else
        @mid = num
      end
    else
      if num > @mid
        @h2.push num
        @h1.push @mid
      else
        @h1.push num
        @h2.push @mid
      end
      @mid = nil
    end
  end

  # @return {double}
  # Returns median of current data stream
  def find_median()
    @mid.nil? ? (@h1.top + @h2.top) / 2.0 : @mid
  end
end

# Your MedianFinder object will be instantiated and called as such:
# mf = MedianFinder.new
# mf.add_num(1)
# mf.find_median()

class Heap
  def initialize(op)
    @arr = []
    @comparer = op
  end

  def push(num)
    @arr.push num
    heap_up
  end

  def pop
    ret = @arr[0]
    @arr[0] = @arr[-1]
    @arr.pop
    heap_down
    ret
  end
  
  def top
    @arr[0]
  end

  def size
    @arr.size
  end

  def empty?
    @arr.empty?
  end

private
  def heap_up
    i = size - 1
    while i > 0 and @arr[i].send(@comparer, @arr[(i-1)/2])
      @arr[i], @arr[(i-1)/2] = @arr[(i-1)/2], @arr[i]
      i = (i-1) / 2
    end
  end

  def heap_down
    i = 0
    while true
      child1 = i*2 + 1
      child2 = i*2 + 2
      break unless child1 < size
      nexti = (child2 >= size or @arr[child1].send(@comparer, @arr[child2])) ? child1 : child2
      if @arr[nexti].send(@comparer, @arr[i])
        @arr[nexti], @arr[i] = @arr[i], @arr[nexti]
        i = nexti
      else
        break
      end
    end
  end
end
