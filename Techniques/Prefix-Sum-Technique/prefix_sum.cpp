#include<bits/stdc++.h>
using namespace std;

//find the prefix array of the given array
// Time -> O(N)
// Space -> O(N)
void prefixSum(vector<int>&vec,vector<int>&prefix){
    int sum = 0;
    for(int i = 0; i < vec.size(); i++){
        sum += vec[i];
        prefix.push_back(sum);
    }
}

int main(){
    vector<int>vec = {2,3,4,5,56,67,78,1};
    int n = vec.size();
    vector<int>prefix;
    prefixSum(vec,prefix);
    for(auto x : prefix){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}