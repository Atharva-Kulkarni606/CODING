#include<bits/stdc++.h>
using namespace std;


//IMPLEMENT TRIE DATA STRUCTURE SUPPORTING 3 OPERATIONS
// 1) Trie(): Initialize the object of this “TRIE” data structure.
// 2) insert(“WORD”): Insert the string “WORD”  into this “TRIE” data structure.
// 3) countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.
// 4) countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.
// 5) erase(“WORD”): Delete this string “WORD” from the “TRIE”.



struct Node {
	Node *links[26];
	int ew;
	int cp;

	Node() {
		ew = 0;
		cp = 0;
	}

	bool containsKey(char ch) {
		return links[ch - 'a'] != NULL; 
	}

	Node *getNextNode(char ch) {
		return links[ch - 'a'];
	}

	void setNewNode(char ch, Node *newNode) {
		links[ch - 'a'] = newNode;
	}
};	



class Trie {
private:
	Node *root;
public:
	Trie() {
		root = new Node();
	}

	//insert -> Inserts the word into the trie
	//Time-Complexity -> O(Len Of Word)
	void insert(string &word) {
		Node *node = root;
		for(int i = 0; i < word.size(); i++) {
			if(!(node -> containsKey(word[i]))) {
				node -> setNewNode(word[i], new Node());
			}
			node = node -> getNextNode(word[i]);
			//Increment the cp(count prefix)
			node -> cp += 1;
		}
		//Increment the ew(end Word count)
		node -> ew += 1;
	}

	//countWordsEqualTo -> Returns count of total words present in trie
	//Time-Complexity -> O(Len Of Word)
	int  countWordsEqualTo(string &word) {
		Node *node = root;
		for(int i = 0; i < word.size(); i++) {
		 	if(!node -> containsKey(word[i])) {
		 		//Letter not present so directly return false
		 		return 0;
		 	}
		 	node = node -> getNextNode(word[i]);
		}

		 return node -> ew;
	}

	// countWordsStartingWith -> Returns count of total words having 
	//prefix 'prefix'
	//Time-Complexity -> O(Len Of Word)
	int countWordsStartingWith(string &prefix) {
		Node *node = root;
		for(int i = 0; i < prefix.size(); i++) {
		 	if(!node -> containsKey(prefix[i])) {
		 		//Letter not present so directly return false
		 		return 0;
		 	}
		 	node = node -> getNextNode(prefix[i]);
		}
		 return node -> cp;
	}

	//erase -> Erases the word from the trie 
	//Time-Complexity -> O(Len Of Word)
	void erase(string &word) {
		Node *node = root;
        for(int i = 0; i < word.size(); i++) {
        	if(node -> containsKey(word[i])) {
        		node = node -> getNextNode(word[i]);
        		//Reduce cp by 1
        		node -> cp -= 1;
        	} else {
        		//If the word isnt present
        		return;
        	}
		}
		//Reduce ew by 1 as this word is removed
		node -> ew -= 1;
    }

};

	
int main() {
	Trie trie1

}