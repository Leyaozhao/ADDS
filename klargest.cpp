#include <queue>
#include <vector>
using namespace std;


int kth_largest(vector<int> values, int k){
    priority_queue <int, vector<int>, less<int>> pq;
    for (int i=0;i<values.size();i++){
        pq.push(values.at(i));
    }
    for (int i=0;i<k-1;i++){
            pq.pop(); 
    }
    return pq.top();
}