class Solution {
public:
    int bestRotation(vector<int>& A) {
        int size = A.size(), score = 0;
    vector<int> bad_intervals(size);

    // for bad intervals for each element from the array
    for(int i = 0; i < size; i++){
        int num = A[i];
        if(num <= i) score++;
        
        // if A[i] element ends up between left and right index of given array, it will not score
        int left = (i - num + 1 + size) % size;
        int right = (i + 1) % size;
        
        // create an interval [left, right] which is not good for A[ith] element
        bad_intervals[left]--;
        bad_intervals[right]++;
        
        // if the bad interval for A[i] is wrapped around the array
        // split the interval into two intervals [0, left] and [right, 10];
        // we do not need to store 10th value for interval - not useful
        if(left > right)
            bad_intervals[0]--; 
        
    }
    
    // after this point apply merge-intervals logic
    // see leetcode questions on merging intervals
    // in short, minimum overlap inerval is the answer 
    int k = 0, max_score = score;
    for(int i = 1; i < size; i++){
        score += bad_intervals[i];
        if(max_score < score)
            max_score = score, k = i;
    }
    
    return k;
    }
};