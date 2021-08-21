#include<bits/stdc++.h>
using namespace std;


//Max Sum Subarray of size K 
int maxSumSubArray( vector<int>&vec,int k){

    int sum = 0,mx = 0;
    // Step 1 -> first fix the window size 
    for(int i = 0 ; i < k ; i++){
        sum += vec[i];
    }
    mx = sum;
    // step2 -> Try all possible windows of size k and find optimal ans 
    for(int i = k ; i < vec.size(); i++){
        sum += vec[i];
        sum -= vec[i - k];
        mx = max(sum,mx);
    }
    //Return the result
    return mx;
}


int main(){
    int n,k;
    cin >> n >> k;
    vector<int>vec;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    cout << maxSumSubArray(vec,k) << endl;
    return 0;
}