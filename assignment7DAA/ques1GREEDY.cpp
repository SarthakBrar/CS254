#include<bits/stdc++.h>
using namespace std;

int Knapsack(int weight[], int value[], int MaxWeight , unordered_map<int,int> st ){
    int MaxValue = 0;
    sort(value, value + 5);
    for(int i = 4; i > 0; i--){
        if(st[value[i]] <= MaxWeight){
            MaxValue += value[i];
            MaxWeight -= st[value[i]]; 
        }
    }

    return MaxValue;
}

int main(){
    int weight[5] = {2, 5, 7, 3, 1};
    int value[5] = {10, 20, 15, 7, 5};
    int MaxWeight = 10;

    unordered_map<int, int> st;
    for(int i = 0; i < 5; i++){
        st[value[i]] = weight[i];
    }

    int MaxValue = Knapsack(weight, value, MaxWeight, st);

    cout << "Max value : " << MaxValue;

    return 0;
}
