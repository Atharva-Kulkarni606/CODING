#include<bits/stdc++.h>
using namespace std;

class Node{
    public : 
        int data;
        Node *left;
        Node *right;
    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }

};


int main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right new Node(30);
    return 0;
}