# Definition for an interval.
# class Interval
#     attr_accessor :start, :end
#     def initialize(s=0, e=0)
#         @start = s
#         @end = e
#     end
# end

# @param {Interval[]} intervals
# @param {Interval} new_interval
# @return {Interval[]}
def insert(intervals, new_interval)
  res = Array.new intervals.size + 1, nil  
  to_insert = bsearch intervals, new_interval
  i = 0
  while i < to_insert
    res[i] = intervals[i]
    i += 1
  end
  res[i] = new_interval
  i += 1
  while i - 1 < intervals.size
    res[i] = intervals[i-1]
    i += 1
  end

  i, j = 0, 0
  while j < res.size
    if i > 0 and res[i-1].end >= res[j].start
      res[i-1].end = [res[i-1].end, res[j].end].max
    else
      res[i] = res[j]
      i += 1
    end
    j += 1
  end
  res.take i
end


def bsearch(intervals, target)
  b, e = 0, intervals.size - 1
  while b < e
    mid = (e - b) / 2 + b
    if intervals[mid].start < target.start
      b = mid + 1
    elsif intervals[mid].start == target.start
      return mid
    else
      e = mid
    end
  end
  (intervals.empty? or intervals[b].start >= target.start) ? b : b + 1
end
