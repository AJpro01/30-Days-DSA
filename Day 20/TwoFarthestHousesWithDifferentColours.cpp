class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int fromLeft = 0;
        int fromRight = 0;
        int n = colors.size();
        int result = 0;

        for(int i = 0;i<n;i++){
            if(colors[i] != colors[n-1]){
                result = max(result, abs(i-n+1));
            }
            if(colors[i] != colors[0]){
                result = max(result, i);
            }
        }

        return result;
        
    }
};