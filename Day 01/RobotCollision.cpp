class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector <int> actual_index(n);
        for (int i =0;i<n; i++){
            actual_index[i] = i;
        }

        auto lambda =[&](int &i, int &j){
            return positions[i] < positions[j];   
        };

        sort(begin(actual_index), end(actual_index), lambda);

        vector<int> result;
        stack<int> st;
        for (int &currIndex:actual_index){
            if (directions[currIndex] == 'R'){
                st.push(currIndex);
            }else{
                while(!st.empty() && healths[currIndex] > 0){
                    int top_idx = st.top();
                    st.pop();

                    if(healths[top_idx] > healths[currIndex]){
                        healths[top_idx] = healths[top_idx] - 1;
                        healths[currIndex] = 0;
                        st.push(top_idx);
                    }else if (healths[top_idx] < healths[currIndex]){
                        healths[currIndex] = healths[currIndex] -1;
                        healths[top_idx]=0;
                        
                    }else{
                        healths[currIndex] =0;
                        healths[top_idx] = 0;
                    }

                    
                        
                }
            }
        }
        for (int i = 0; i< n; i++){
            if (healths[i] > 0){
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};