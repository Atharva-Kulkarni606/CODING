#include<bits/stdc++.h>
using namespace std;


void inOrder(Node *root){
    if(root == NULL){
        return;
    }
    preOrder(root -> left);
    cout << root -> data << " ";
    preOrder(root -> right);

}

int main(){
    preOrder(root);
    return 0;
}