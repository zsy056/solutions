# @param {Integer} num_courses
# @param {Integer[][]} prerequisites
# @return {Boolean}
def can_finish(num_courses, prerequisites)
  pres = (0...num_courses).map {|i| [i, []]}.to_h
  pre_counts = Array.new num_courses, 0
  prerequisites.each do |p|
    pres[p[1]].push p[0]
    pre_counts[p[0]] += 1
  end
  q = pre_counts.each_index.select {|i| pre_counts[i] == 0}
  taken = 0
  while not q.empty?
    taken += q.size
    q = q.flat_map do |i|
      pres[i].select do |j|
        pre_counts[j] -= 1
        pre_counts[j] == 0
      end
    end
  end
  taken == num_courses
end

