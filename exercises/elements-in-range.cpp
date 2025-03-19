// program to insert the any no in given array according to range 
// {1,2,8,5,9,6,15,17,18,19} find no of consecutive and store it in array 
// if there is no consecutive create in seperate array 


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findConsecutives(vector<int>& arr){
    sort(arr.begin() , arr.end());

    vector<vector<int>> res;
    vector<int> tmp;
    tmp.push_back(arr[0]);
    for(int i = 1 ; i < arr.size() ; i++){
        if(arr[i] == arr[i - 1] + 1){ // consecutive found
            tmp.push_back(arr[i]);
        }
        else{
            res.push_back(tmp);
            tmp.clear();
            tmp.push_back(arr[i]);
        }
    }
    res.push_back(tmp);
    return res;
}

int main(){
    vector<int> v = {1,2,8,5,9,6,15,17,18,19};
    
    vector<vector<int>> ans = findConsecutives(v);

    for(auto& it : ans){
        cout << "[";
        for(int i : it){
            cout << i << " ";
        }
        cout << "]" ;
        cout << endl;
    }
        

return 0;
}