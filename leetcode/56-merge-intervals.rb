# Definition for an interval.
# class Interval
#     attr_accessor :start, :end
#     def initialize(s=0, e=0)
#         @start = s
#         @end = e
#     end
# end

# @param {Interval[]} intervals
# @return {Interval[]}
def merge(intervals)
  intervals.sort! { |a, b| a.start <=> b.start }
  res = []
  intervals.each do |interval|
    if res.empty? or interval.start > res[-1].end
      res.push interval
    else
      res[-1].end = [res[-1].end, interval.end].max
    end
  end
  res
end
