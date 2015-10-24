# @param {Integer} num_courses
# @param {Integer[][]} prerequisites
# @return {Integer[]}
def find_order(num_courses, prerequisites)
  deps = prerequisites.group_by { |i| i[1] }
  num_deps = prerequisites.group_by { |i| i[0] }
  num_deps.each { |k, v| num_deps[k] = v.size }
  q = (0...num_courses).select { |x| not num_deps.include? x }
  order = []
  while not q.empty?
    c = q.pop
    order.push c
    if deps.include? c
      deps[c].each do |pre|
        num_deps[pre[0]] -= 1
        q.push pre[0] if num_deps[pre[0]] == 0
      end
    end
  end
  order.size == num_courses ? order : []
end
