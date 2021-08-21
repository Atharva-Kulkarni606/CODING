#include<bits/stdc++.h>
using namespace std;

//Linear Search -> Searches an element from an array in 
                //    Time - O(N)
                //    Space - O(1)


bool linearSearch(vector<int>&vec,int key){
    int n = vec.size();
    for(int i = 0 ; i < n ; i++){
        if(vec[i] == key){
            return true;
        }
    }
    return false;
}


int main(){
    vector<int>vec = {1,4,7,8,9,44,21,0};
    int key = 5; 
    cout << linearSearch(vec,key) << endl;
    return 0;
}