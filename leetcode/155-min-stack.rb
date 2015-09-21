class MinStack
  # Initialize your data structure here
  def initialize
    @stk = []  
    @minstk = []
  end

  # @param {Integer} x
  # @return {Void} nothing
  def push(x)
    @stk.push x
    @minstk.push x if @minstk.empty? or @minstk[-1] >= x
  end

  # @return {Void} nothing
  def pop
    x = @stk.pop  
    @minstk.pop if (not @minstk.empty?) and x == @minstk[-1]
  end

  # @return {Integer}
  def top
    @stk[-1]
  end

  # @return {Integer}
  def get_min
    @minstk[-1]
  end
end
