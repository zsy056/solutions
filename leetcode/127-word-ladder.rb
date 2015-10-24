# @param {String} begin_word
# @param {String} end_word
# @param {Set<String>} word_list
# @return {Integer}
def ladder_length(begin_word, end_word, word_list)
  way1, way2 = [Set.new([begin_word])], [Set.new([end_word])]
  state = 0
  to_delete = []
  turn = 0
  while true
    way1[-1].each do |word|
      if way2[-1].include? word
        return way1.size + way2.size - 1
      end
    end
    way1_nxt = Set.new
    way1[-1].each do |word|
      (0...word.size).each do |i|
        oc = word[i]
        tword = word.dup
        ('a'..'z').each do |c|
          next if oc == c
          tword[i] = c
          if word_list.include? tword
            way1_nxt.add tword
            to_delete.push tword
          end
          tword[i] = oc
        end
      end
    end
    if turn == 1
      to_delete.each { |word| word_list.delete word }
      to_delete = []
    end
    turn = 1 - turn
    way1.push way1_nxt unless way1_nxt.empty?
    puts way1.to_s
    way1, way2 = way2, way1
    state += 1 if way1_nxt.empty?
    break if state == 2
  end
  0
end

#require 'set'

#puts ladder_length 'hot', 'dog', Set.new(['hot', 'dog', 'dot'])
