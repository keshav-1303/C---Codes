#include <bits/stdc++.h>
using namespace std;

// What is Trie?
// Trie is a type of k-ary search tree used for storing and searching a specific key 
// from a set. Using Trie, search complexities can be brought to optimal limit (key length). 
// Used for inserting, Searching words.

class Node {
public:
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        if(links[ch - 'a'] != NULL)    return 1;
        else    return 0;
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
        // i.e now a will have ch a new trie.
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    bool setEnd(){
        return flag;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {

private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    // T.C = O(length of word)
    void insert(string word){
        Node* node = root;
        for(int i=0 ; i<word.size() ; i++){
            if(!node -> containsKey(word[i])){
                // if that char is not present
                node -> put(word[i], new Node());
            }
            // now move to the new reference trie...
            node -> get(word[i]);
        }

        node -> setEnd();
    }

    // T.C = O(length of word)
    bool search(string word){
        Node* node = root;
        for(int i=0 ; i<word.size() ; i++){
            if(!node -> containsKey(word[i])){
                return false;
            }
            else{
                node = node -> get(word[i]);
            }
        }

        // Now we are at end OR not, we've to check
        if(node -> isEnd()){
            return true;
        }
        else{
            return false;
        }
    }

    // T.C = O(length of word)
    bool startsWith(string word){
        Node* node = root;
        for(int i=0 ; i<word.size() ; i++){
            if(!node -> containsKey(word[i])){
                return false;
            }
            else{
                node = node -> get(word[i]);
            }
        }

        // Now we are at end so, no need to check just return true;
        return true;
    }
};

int main(){


}