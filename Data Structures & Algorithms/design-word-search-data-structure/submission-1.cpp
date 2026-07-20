class trie{
    public:
    trie* links[26]={nullptr};
    bool fg=false;

    void insertch(char ch){
    links[ch-'a']=new trie();}

    trie* getchar(char ch)
    {
        return links[ch-'a'];
    }
    bool isend()
    {
        return fg;
    }
    void endword()
    {
        fg=true;
    }

};
class WordDictionary {
public:
trie* root;
    WordDictionary() {
        root=new trie();
    }
    
    void addWord(string word) {
        trie* curr=root;
        for(int i=0;i<word.size();i++)
        {char ch=word[i];
            if(!curr->getchar(ch))
            curr->insertch(ch);
            curr=curr->getchar(ch);
        }
        curr->endword();
    }
    
    bool search(string word) {
        trie* curr=root;
        for(int i=0;i<word.size();i++)
        {char ch=word[i];
        if(ch=='.')
{
    for(int k=0;k<26;k++)
    {word[i]=k+'a';
    if(search(word))
    return true;
    }
    return false;
}
        else{
            if(!curr->getchar(ch))
            return false;
            curr=curr->getchar(ch);}
        }
        return curr->isend();
    }
};
