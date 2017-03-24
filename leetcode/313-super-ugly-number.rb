# @param {Integer} n
# @param {Integer[]} primes
# @return {Integer}
def nth_super_ugly_number(n, primes)
  results = Array.new n+1
  results[1] = 1
  seq = 2
  heap = MinHeap.new
  primes.each { |x| heap.push Elem.new(x, 1, x) }
  while n >= seq
    min_elem = heap.peek
    results[seq] = min_elem.x
    seq += 1
    while heap.peek.x == min_elem.x
      tmp = heap.pop
      heap.push Elem.new(tmp.prime * results[tmp.i+1], tmp.i+1, tmp.prime)
    end
  end
  results[n]
end

class Elem
  attr_reader :x, :i, :prime
  def initialize(x, i, prime)
    @x = x
    @i = i
    @prime = prime
  end

  def <=>(other)
    @x <=> other.x
  end
end

class MinHeap

  def initialize()
    @elem = [nil]
  end

  def push(x)
    @elem << x
    i = @elem.size - 1
    while i > 1
      if (@elem[i/2] <=> @elem[i]) > 0
        @elem[i/2], @elem[i] = @elem[i], @elem[i/2]
        i /= 2
      else
        break
      end
    end
    #puts x.x
    #puts @elem.map { |e| e.x if e }.to_s
  end

  def pop()
    tmp = peek
    @elem[1] = @elem[-1]
    @elem.pop
    i = 1
    while i < @elem.size
      to_change = -1
      if i*2+1 < @elem.size
        to_change = if (@elem[i*2] <=> @elem[i*2+1]) <= 0
                      i*2
                    else
                      i*2+1
                    end
      elsif i*2 < @elem.size
        to_change = i*2
      else
        break
      end
      if (@elem[i] <=> @elem[to_change]) > 0
        @elem[i], @elem[to_change] = @elem[to_change], @elem[i]
        i = to_change
      else
        break
      end
    end
    tmp
  end

  def peek()
    @elem[1]
  end
end

puts (1..12).map { |n| nth_super_ugly_number n, [2, 7, 13, 19] }.to_s
