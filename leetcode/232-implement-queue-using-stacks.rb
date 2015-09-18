class Queue
  # Initialize your data structure here.
  def initialize
    @stk1 = []
    @stk2 = []
  end

  # @param {Integer} x
  # @return {void}
  def push(x)
    @stk1.push x
  end

  # @return {void}
  def pop
    if @stk2.empty?
      while not @stk1.empty?
        @stk2.push(@stk1.pop)
      end
    end
    @stk2.pop
  end

  # @return {Integer}
  def peek
    if @stk2.empty?
      while not @stk1.empty?
        @stk2.push(@stk1.pop)
      end
    end
    @stk2[-1]
  end

  # @return {Boolean}
  def empty
    @stk1.empty? and @stk2.empty?
  end
end
