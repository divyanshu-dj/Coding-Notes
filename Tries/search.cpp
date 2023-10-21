class Trie {
  public:
  TrieNode* root;

  Trie() {
    root = new TrieNode('\0');
    return;
  }

  bool searchUtil(TrieNode* root, string word) {
    //base case
    if( word.length()==0 ) {
      return root->isTerminal;
    }

    int index = word[0] - 'A';
    TrieNode* child;

    //present
    if(root->children[index] != NULL) {
      child = root->children[index];
    }
    else {
      //absent
      return false;
    }

    //recursion
    return searchUtil(child, word.substr(1));
  }

  bool searchWord(string word) {
    return searchUtil(root, word);
  }
};


int main() {
  Trie* t = new Trie();

  cout<<"1 if present and 0 if not: "<< t->searchWord("abcd")<<endl;
}
