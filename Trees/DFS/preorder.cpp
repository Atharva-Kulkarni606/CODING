#include<bits/stdc++.h>
using namespace std;


void preOrder(Node *root){
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);

}

int main(){
    preOrder(root);
    return 0;
}