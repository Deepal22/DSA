struct TrieNode {
    unordered_map<char, TrieNode*> chars;
    int len_word;
    int best;

    TrieNode() : len_word(INT_MAX), best(-1) {}
};

class Trie {
public:
    TrieNode* root;
    vector<TrieNode*> nodes;
    Trie() {
        root = new TrieNode();
        nodes.push_back(root);
    }
    ~Trie() {
        for (auto node : nodes) 
            delete node;
    }

    void insert(int idx, const string& word) {
        TrieNode* curr = root;
        for (int i = word.length() - 1; i >= 0; --i) {
            char c = word[i];
            if (curr->chars.find(c) == curr->chars.end()) {
                TrieNode* newNode = new TrieNode();
                curr->chars[c] = newNode;
                nodes.push_back(newNode);
            }
            curr = curr->chars[c];
            
            if (curr->best == -1 || curr->len_word > (int)word.length()) {
                curr->best = idx;
                curr->len_word = (int)word.length();
            }
        }
    }

    int search(const string& word) {
        TrieNode* curr = root;
        int idx = -1;
        for (int i = word.length() - 1; i >= 0; --i) {
            char c = word[i];
            if (curr->chars.find(c) == curr->chars.end()) break;
            curr = curr->chars[c];
            idx = curr->best;
        }
        return idx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie;
        int min_len_idx = 0;
        
        for (int i = 0; i < wordsContainer.size(); ++i) {
            trie.insert(i, wordsContainer[i]);
            if (wordsContainer[min_len_idx].length() > wordsContainer[i].length()) {
                min_len_idx = i;
            }
        }

        vector<int> ans;
        for (const string& word : wordsQuery) {
            int idx = trie.search(word);
            if (idx == -1) {
                ans.push_back(min_len_idx);
            } else {
                ans.push_back(idx);
            }
        }
        return ans;
    }
};