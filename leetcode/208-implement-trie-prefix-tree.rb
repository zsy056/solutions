class TrieNode
    attr_accessor :ending
    # Initialize your data structure here.
    def initialize(is_ending)
      @mapping = Hash.new  
      @ending = is_ending
    end

    def next_node(c)
      @mapping[c]
    end

    def add_child(c, node)
      @mapping[c] = node
    end

end

class Trie
    def initialize
        @root = TrieNode.new false
    end

    # @param {string} word
    # @return {void}
    # Inserts a word into the trie.
    def insert(word)
      current = @root
      word.each_char do |c|
        next_node = current.next_node c
        if next_node.nil?
          next_node = current.add_child c, TrieNode.new(false)
        end
        current = next_node
      end
      current.ending = true
    end

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the trie.
    def search(word)
      current = prefix_node word
      (not current.nil?) and current.ending
    end

    # @param {string} prefix
    # @return {boolean}
    # Returns if there is any word in the trie
    # that starts with the given prefix.
    def starts_with(prefix)
      current = prefix_node prefix 
      not current.nil?
    end

    def prefix_node(prefix)
      current = @root
      prefix.each_char do |c|
        current = current.next_node c
        break if current.nil?
      end
      current
    end

    private :prefix_node
end

# Your Trie object will be instantiated and called as such:
# trie = Trie.new
# trie.insert("somestring")
# trie.search("key")
