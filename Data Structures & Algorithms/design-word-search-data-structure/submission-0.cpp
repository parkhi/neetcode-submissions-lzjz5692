class TrieNode {
public:
    TrieNode* children[26];
    bool isleafnode;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isleafnode = false;
    }
};

class WordDictionary {
     TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;

        for (char ch : word) {
            if (!(cur->children[ch-'a'])) {
                TrieNode* node = new TrieNode();
                cur->children[ch-'a'] = node;
                cur = node;
            }
            else {
                cur = cur->children[ch-'a'];
            }
        }
        cur->isleafnode = true;
    }
    bool search1(string word, TrieNode* cur) {

        if(!cur) {
            return false;
        }

        for (int i=0; i<word.length(); i++) {

            if ((word[i] != '.') && !(cur->children[word[i]-'a'])) {
                return false;
            }
            else if((word[i] != '.') && (cur->children[word[i]-'a'])){
                cur = cur->children[word[i]-'a'];
            }
            else {
                for (int j=0; j<26; j++) {
                    if(cur->children[j] != nullptr) {
                        TrieNode* temp = cur->children[j];
                        if(search1(word.substr(i+1,word.length()-i-1), temp))
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
       
    }
     return cur->isleafnode;
    }

    bool search(string word) {
        return search1(word, root);
    }
};
