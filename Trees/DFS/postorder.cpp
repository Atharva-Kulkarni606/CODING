#include<bits/stdc++.h>
using namespace std;


void postOrder(Node *root){
    if(root == NULL){
        return;
    }
    preOrder(root -> left);
    preOrder(root -> right);
    cout << root -> data << " ";
}

int main(){
    preOrder(root);
    return 0;
}