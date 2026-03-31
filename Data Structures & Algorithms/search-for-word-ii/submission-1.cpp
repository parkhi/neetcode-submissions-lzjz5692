class TrieNode {
public:
    TrieNode* children[26];
    int index;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        index = -1 ;
    }
};


class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        cout<<"cons";
        root = new TrieNode();
    }
    
    void insert(string word, int index) {
      //  cout<<"word index "<<word<<" "<<index<<endl;
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
        cur->index = index;
    }
};

class Solution {
    void find(  vector<vector<char>>& board, vector<string>& words, 
                TrieNode* cur, int r , int c, vector<string>& res) {
            
            if( board.empty() || r<0 || c<0 || r>=board.size() || c>=board[0].size() ||
                words.empty() || !cur || board[r][c]=='#') {
                    return;
                }
           // cout<<" here"<<endl;
            TrieNode* nextNode = cur->children[board[r][c]-'a'];
            if( nextNode != nullptr) {
                if(nextNode->index != -1) {
                    res.push_back(words[nextNode->index]);
                   // cout<<" here1"<<endl;
                    nextNode->index = -1;
                }

              //  cout<<" here2"<<endl;
                char ch = board[r][c];
                board[r][c] = '#';
                find(board, words, cur->children[ch-'a'],r+1,c,res);
                find(board, words, cur->children[ch-'a'],r-1,c,res);
                find(board, words, cur->children[ch-'a'],r,c+1,res);
                find(board, words, cur->children[ch-'a'],r,c-1,res);
                board[r][c] = ch;

            } 
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        PrefixTree* trie = new PrefixTree();
       // cout<<"here"<<endl;
        for (int i = 0; i<words.size(); i++) {
            trie->insert(words[i], i);
        }
        vector<string> res;

        for(int r=0; r<board.size(); r++) {
            for( int c=0; c<board[0].size(); c++) {
                find(board, words, trie->root, r , c, res);
            }
        }

        return res;
    }
};
