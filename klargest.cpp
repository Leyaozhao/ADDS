#include<vector>



int kth_largest(vector<int> values, int k){
    int size=values.size();
    priority_queue <int, vector<int>, less<int>> pq;
    for (int i=0;i<size;i++){
        pq.push(values.at(i));
    }
    for (int i=0;i<k-1;i++){
            pq.pop(); 
    }
    return pq.top();
}