class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    //Find Node
    TrieNode* nodeFinder(TrieNode *root,string pattern){
        if(pattern.size()==0){
			return root;
        }
        int index=pattern[0]-'a';
        if(root->children[index]==NULL){
            return NULL;
        }else{
            return nodeFinder(root->children[index],pattern.substr(1));
        }
    }
    bool isEmpty(TrieNode *root){
        
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                return false;
            }
        }
        return true;
    }
    
    //Print suggestion 
    void printSuggestion(TrieNode* root,string pattern){
    	
        if(isEmpty(root)){
            cout<<pattern<<endl;
            return;
        }
        if(root->isTerminal){
            cout<<pattern<<endl;
        }
        
        for(int i=0;i<26;i++){
            if(root->children[i]==NULL){
                continue;
            }else{
                string appended=pattern+root->children[i]->data;
                printSuggestion(root->children[i], appended);
            }
        }
    }
    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        bool small;
        for(int i=0;i<input.size();i++){
            small=insertWord(root,input[i]);
        }
        TrieNode *smallRoot=nodeFinder(root,pattern);
        if(!smallRoot){
            return;
        }
        printSuggestion(smallRoot,pattern);
    	}
};