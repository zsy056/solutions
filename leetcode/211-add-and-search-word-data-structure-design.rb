class WordDictionary

  def initialize
    @root = TrieNode.new
  end

  # @param {string} word
  # @return {void}
  # Adds a word into the data structure.
  def add_word(word)
    current = @root
    word.each_char do |c|
      idx = c.ord - 'a'.ord
      current.children[idx] = TrieNode.new if current.children[idx].nil?
      current = current.children[idx]
    end
    current.end = true
  end

  # @param {string} word
  # @return {boolean}
  # Returns if the word is in the data structure. A word could
  # contain the dot character '.' to represent any one letter.
  def search(word)
    _search word, @root
  end

  def _search(word, current)
    word.chars.each_with_index do |c, i|
      if c == '.' and wild_search word[i..-1], current
        return true
      else
        idx = c.ord - 'a'.ord
        current = current.children[idx]
        return false if current.nil?
      end
    end
    current.end
  end

  def wild_search(word, current)
    (0..25).each do |i|
      return true if (not current.children[i].nil?) and _search word[1..-1], current.children[i]
    end
    false
  end
end

# Your WordDictionary object will be instantiated and called as such:
# word_dictionary = WordDictionary.new
# word_dictionary.add_word("word")
# word_dictionary.search("pattern")

class TrieNode
  attr_accessor :end

  def initialize
    @children = Array.new 26, nil
    @end = false
  end

  def children
    @children
  end

end


