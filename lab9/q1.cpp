#include <bits/stdc++.h>
using namespace std;
class Trie {
public:
    vector <Trie*> children;
    vector <int> frequency;
    Trie() {
        for (int i=0;i<26;i++){
                this->children.push_back(nullptr);
            }
        for (int i=0;i<26;i++){
                this->frequency.push_back(0);
            }
    }
    
    void ins(Trie* T, string word, int &i){
        int index = static_cast<int>(word[i])-static_cast<int>('a');
        if (i != word.length()-1){
            if (T->children[index] != nullptr){
                i++;
                ins(T->children[index],word,i);
            }

            else{
                Trie* t = new Trie();
                T->children[index] = t;
                i++;
                ins(T->children[index],word,i);
            }
        }
        else{
            T->frequency[index] += 1;
        }

}


    void insert(string word) {
        int i=0;
        ins(this,word,i);
    }
    
    int sea(Trie* T,string word, int& i){
        int index = static_cast<int>(word[i])-static_cast<int>('a');
        if (i != word.length()-1){
            if (T->children[index] != nullptr){
                i++;
                return sea(T->children[index],word,i);
            }

            else{
                return 0;
            }
        }
        else{
            return T->frequency[index];
        }
}


    bool search(string word) {
        int i=0;
        return sea(this,word,i);
    }
    
    
    bool startsWith(string prefix){
        int i=0;
        return startsWit(this,prefix,i);
    }
    bool startsWit(Trie* T,string word, int& i) {
        int index = static_cast<int>(word[i])-static_cast<int>('a');
        if (i != word.length()-1){
            if (T->children[index] != nullptr){
                i++;
                return startsWit(T->children[index],word,i);
            }

            else{
                return false;
            }
        }
        else{
            if (T->children[index] != nullptr || T->frequency[index]>=1){
                return true;
            }

            else{
                return false;
            }
        }
    }
};


