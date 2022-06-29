class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        };
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> peopleAfter;
        for (int i = 0; i < people.size(); i++) {
            if (people[i][1] == peopleAfter.size()) {
                // Heights of all previous people are greater or equal to
                // current person.
                peopleAfter.push_back(people[i]);
            } else {
                // Insert at correct position
                peopleAfter.insert(peopleAfter.begin() + people[i][1],
                                   people[i]);
            }
        }
        return peopleAfter;
    }
};