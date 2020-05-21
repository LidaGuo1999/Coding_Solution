class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int ans = recursion(pizza, k-1);
        return ans;
    }
    
    int recursion(vector<string> pizza, int k) {
        int ans = 0;
        if (k == 0 || pizza.size() == 0) return 0;
        int flag = 0;
        for (int i = 0; i < pizza.size()-1; i++) {
            if (flag == 0) {
                for (int j = 0; j < pizza[0].size(); j++) {
                    if (pizza[i][j] == 'A') {
                        flag = 1;
                        break;
                    }
                }
            }
            
            if (flag == 1) {
                vector<string> npizza;
                npizza.assign(pizza.begin()+i+1, pizza.end());
                ans += recursion(npizza, k-1);
            }
        }
        
        flag = 0;
        for (int j = 0; j < pizza[0].size()-1; j++) {
            if (flag == 0) {
                for (int i = 0; i < pizza.size(); i++) {
                    if (pizza[i][j] == 'A') {
                        flag = 1;
                        break;
                    }
                }
            }
            
            if (flag == 1) {
                vector<string> npizza;
                for (int i = 0; i < pizza.size(); i++) {
                    npizza.push_back(pizza[i].substr(j+1));
                    ans += recursion(npizza, k-1);
                }
            }
        }
        
        return ans;
    }
};