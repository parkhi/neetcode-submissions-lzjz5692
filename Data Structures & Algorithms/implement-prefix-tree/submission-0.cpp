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

class PrefixTree {
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
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
    
    bool search(string word) {

        TrieNode* cur = root;

        for (char ch : word) {
            if (!(cur->children[ch-'a'])) {
                return false;
            }
            else {
                cur = cur->children[ch-'a'];
            }
        }
        
        return cur->isleafnode;
    }
    
    bool startsWith(string prefix) {

        TrieNode* cur = root;

        for (char ch : prefix) {
            if (!(cur->children[ch-'a'])) {
                return false;
            }
            else {
                cur = cur->children[ch-'a'];
            }
        }
        
        return true;
    }
};
