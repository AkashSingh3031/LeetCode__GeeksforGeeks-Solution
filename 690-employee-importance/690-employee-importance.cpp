/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*>m;
        for(auto x: employees) m[x->id] = x;
        int sum = 0;
        deque<Employee*>q;
        q.push_back(m[id]);
        while(!q.empty()){
            auto p = q.front();
            q.pop_front();
            for(auto x: p->subordinates) q.push_back(m[x]);
            sum += p->importance;
        }
        return sum;
    }
};