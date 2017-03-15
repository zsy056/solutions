require 'set'
# @param {Integer} n
# @param {Integer[][]} edges
# @return {Integer[]}
def find_min_height_trees(n, edges)
  mtx = (0...n).map { |x| [x, Set.new] }.to_h
  edges.each do |edge|
    mtx[edge[0]] << edge[1]
    mtx[edge[1]] << edge[0]
  end

  to_remove = mtx.select { |k, v| v.size == 1 }
  while mtx.size > 2
    remove_next = Hash.new
    to_remove.each do |k, v|
      v.each do |i|
        mtx[i].delete k
        if mtx[i].size == 1
          remove_next[i] = mtx[i]
        end
      end
      mtx.delete k
    end
    to_remove = remove_next
  end

  mtx.keys
end

puts find_min_height_trees(6, [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]).to_s
puts find_min_height_trees(4, [[1, 0], [1, 2], [1, 3]]).to_s
