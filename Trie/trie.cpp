#include<bits/stdc++.h>
using namespace std;


//IMPLEMENT TRIE DATA STRUCTURE SUPPORTING 3 OPERATIONS
// 1) insert(word) -> insert the word into trie 
// 2) search(word) -> search this word in trie ds (true or false)
// 3) startsWith(prefix) -> check whether a prefix exists in trie   
      


struct Node {
   Node *links[26];
   bool isEndOfWord = false;
   
   bool containsKey(char ch) {
      return links[ch - 'a'] != NULL;
   }

   void setNewNode(char ch, Node *node) {
      links[ch - 'a'] = node;
   }

   Node *getNextNode(char ch) {
      return links[ch - 'a'];
   }

   void setEnd() {
      isEndOfWord = true;
   }

   bool isEnd() {
      return isEndOfWord;
   }

};

class Trie {
private:
   Node *root;
public:
   Trie() {
      root = new Node();
   }

   //Inserts a word into the trie
   //Time Complexity - O(Len Of Word)
   void insert(string word) {
      Node *node = root;
      for(int i = 0; i < word.length(); i++) {
         if(!(node -> containsKey(word[i]))) {
            //Does not contain then
            //Insert that word and create a new reference
            node -> setNewNode(word[i], new Node());
         }
         //Moves to the reference trie
         node = node -> getNextNode(word[i]);
      }
      node -> setEnd();
   }
   
   //Returns true if the word is present in the trie
   //Time Complexity - O(Len Of Word)
   bool search(string word) {
      Node *node = root;

      for(int i = 0;i < word.length(); i++) {
         if(!(node -> containsKey(word[i]))) {
            return false;
         }
         node = node -> getNextNode(word[i]);
      }

      return node -> isEnd();
   }

   //Returns if there is any word in the trie that starts
   //with the prefix
   //Time Complexity - O(Len Of Word)
   bool startsWith(string prefix) {
      Node *node = root;

      for(int i = 0; i < prefix.length(); i++) {
         if(!node -> containsKey(prefix[i])) {
            return false;
         }
         node = node -> getNextNode(prefix[i]); 
      }
      return true;
   }

};
