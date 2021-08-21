#include<bits/stdc++.h>
using namespace std;

//Binary Search -> Searches an element from an array in 
                //    Time - O(LogN)
                //    Space - O(1)


bool binarySearch(vector<int>&vec,int key){
    int low = 0, high = vec.size() - 1;
    while(low <= high){
        int mid = (low + (high - low) / 2);
        if(vec[mid] == key){
            return true;
        }else if(arr[mid] > key){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return false;
}


int main(){
    vector<int>vec = {1,4,7,8,9,44,21,0};
    int key = 5; 
    cout << binarySearch(vec,key) << endl;
    return 0;
}