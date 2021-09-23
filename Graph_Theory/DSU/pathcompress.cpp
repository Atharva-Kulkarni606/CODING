#include<bits/stdc++.h>
using namespace std;


//PATH COMPRESSION -> JUST OBSERVE FIND FUNCTION -> ITS PATH COMPRESSED (OPTIMISED)

//DSU - > DISJOINT SET UNION 
// //This data structure provides the following capabilities.
//  We are given several elements, each of which is a separate set. 
//  A DSU will have an operation to combine any two sets, and it will be able
//   to tell in which set a specific element is. The classical version also
//  introduces a third operation, it can create a set from a new element.


//HAS 2 FUNCTIONS
// 1)-> FIND(X) -> FINDS THE REPRESENTATIVE / PARENT OF X IN THE COMBINED set
// 2)-> UNION(A,B) - > FIRST USES THE FIND(A) AND FIND(B) TO FIND THE PARENTS OF 
// BOTH A AND B AND THEN COMBINES BOTH SETS INTO A SINGLE ONE MAKING A AS A PARENT 

//NAIVE IMPLEMENTATION

//USED TO MAKE EACH NODE AS ITS OWN PARENT(BASICALLY INITIALIZATION)
void makeSet(vector<int>&parent,int n) {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

//USED TO FIND PARENT OF X
//WHILE BACKTRACKING JUST GO ON STORING ROOT AS A DIRECT PARENT
// OF ALL THE ELEMENTS IN THE PATH FROM CURR -> ROOT 
int find(int x,vector<int>&parent) {
    if(parent[x] == x) {
        return x;
    }
    //PATH COMPRESSED VERSION
    return parent[x] = find(parent[x],parent);
}


//TIME -> O(N)
void union(int a,int b,vector<int>&parent) {
    //STEP1 -> FIND PARENT OF A AND B
    int p1 = find(a,parent);
    int p2 = find(b,parent);
    //IF PARENTS AREN'T SAME -> MAKE P1 AS A PARENT OF P2
    if(p1 != p2) {
        parent[p2] = p1;
    }

}

int main() {
    //NO OF ELEMENTS / NODES
    int n;
    cin >> n;
    vector<int>parent(n + 1,0);
    makeSet(parent,n);
    int x;
    cin >> x;
    int parentOfX = find(x,parent);
    union(n - 1,n - 2,parent);
    return 0;
}