class Trie {
  

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
