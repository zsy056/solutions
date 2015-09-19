class Stack
  # Initialize your data structure here.
  def initialize
    @q1 = []
    @q2 = []
  end

  # @param {Integer} x
  # @return {void}
  def push(x)
    @q1.push x  
  end

  # @return {void}
  def pop
    if @q1.empty?
      @q1 = @q2
      @q2 = []
    end
    while @q1.size > 1
      @q2.push @q1.shift
    end
    @q1.shift
  end

  # @return {Integer}
  def top
    if @q1.empty?
      @q1 = @q2
      @q2 = []
    end
    while @q1.size > 1
      @q2.push @q1.shift
    end
    @q1[0]
  end

  # @return {Boolean}
  def empty
    @q1.empty? and @q2.empty?  
  end
end
