class Trie {
  public:
  TrieNode* root;

  Trie() {
    root = new TrieNode('\0');
    return;
  }

  void insertUtil(TrieNode* root, string word) {

    //base case
    if(word.length() == 0) {
      root->isTerminal = true;
      return;
    }

    //assumption word will be in CAPS
    int index = word[0]-'A';
    TrieNode* child;

    //present
    if(root->children[index] != NULL) {
      child = root->children[index];
    }
    else {
      //absent
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

    //recursion
    insertUtil(child, word.substr(1));
  }

  void insertWord(string word) {
    insertUtil(root, word);
  }



  bool searchUtil(TrieNode* root, string word) {
    //base case
    if( word.length()==0 ) {
      return root->isTerminal;
    }
  }
  bool search(string word) {
    return searchUtil(root, word);
  }
};

int main() {
  Trie *t = new Trie();

  t->insertWord("abc");
}
