class trie{
    public:
    trie* links[26]={nullptr};
    bool fg=false;
trie()
{

}

void insertch(char ch){
links[ch-'a']=new trie();}

trie* getchar(char ch){
return links[ch-'a'];}

bool ischar(char ch){
return links[ch-'a']!=nullptr;}

bool isend(){
return fg;}

void endword(){
fg=true;}

};
class PrefixTree {
public:
trie* root;
    PrefixTree() {
        root=new trie();
    }
    
    void insert(string word) {
        trie* curr=root;
        for(int i=0;i<word.size();i++)
        {char ch=word[i];
            if(!curr->ischar(ch))
curr->insertch(ch);
curr=curr->getchar(ch);
        }
        curr->endword();
    }
    
    bool search(string word) {
         trie* curr=root;
        for(int i=0;i<word.size();i++)
        {char ch=word[i];
            if(!curr->ischar(ch))
return false;
curr=curr->getchar(ch);
        }
        return curr->isend();
    }
    
    bool startsWith(string prefix) {
        trie* curr=root;
        for(int i=0;i<prefix.size();i++)
        {char ch=prefix[i];
            if(!curr->ischar(ch))
return false;
curr=curr->getchar(ch);
        }
        return true;
    }
};
