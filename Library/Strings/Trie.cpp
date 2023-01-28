const int ALPHABET_SIZE = 26;

// Trie node
struct TrieNode {
  TrieNode* children[ALPHABET_SIZE];
  bool isEndOfWord;
  TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; i++) children[i] = nullptr;
    isEndOfWord = false;
  }
};

class Trie {
  TrieNode* root;

 public:
  Trie() { root = new TrieNode(); }

  // Insert a word into the Trie
  void insert(const string& word) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < word.length(); i++) {
      int index = word[i] - 'a';
      if (!pCrawl->children[index]) pCrawl->children[index] = new TrieNode();
      pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
  }

  // Search for a word in the Trie
  bool search(const string& word) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < word.length(); i++) {
      int index = word[i] - 'a';
      if (!pCrawl->children[index]) return false;
      pCrawl = pCrawl->children[index];
    }
    return (pCrawl != nullptr && pCrawl->isEndOfWord);
  }
  // get the max prefix match with words in trie
  int max_prefix(const string& word) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < word.length(); i++) {
      int index = word[i] - 'a';
      if (!pCrawl->children[index]) return i;
      pCrawl = pCrawl->children[index];
    }
    return word.size();
  }
};
