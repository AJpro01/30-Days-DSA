class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int min_distance = INT_MAX;
        int n = words.size();

        for(int i=0; i<n; i++){
            if(words[i]==target){
                int straightDist = abs(i - startIndex);
                int circularDist = n- straightDist;

                min_distance = min({min_distance, straightDist, circularDist});
            }
        }

        return min_distance == INT_MAX ? -1 : min_distance;
    }
};