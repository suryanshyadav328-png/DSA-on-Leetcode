/*  I did it without Graph Theory as i didn't know it */


class Solution {
public:
    void findSuspicious(int k, vector<vector<int>>& calls,vector<bool>& suspicious){

        suspicious[k] = true;                          // method K is suspicious

        for(int next : calls[k]){                      // this will first go in one depth like for 1 -> {2,3} where 2 -> 4 it will first go 1->2->4 then to 3
        
            if(!suspicious[next]){
                findSuspicious(next, calls, suspicious);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> suspicious(n, false);
        

        // calls[i] = methods called by i
        vector<vector<int>> calls(n);   // bcoz it stores a vector for each 

        for(auto x : invocations){
            calls[x[0]].push_back(x[1]);    
        }

        findSuspicious(k, calls, suspicious);


        for(auto x : invocations){              // CHECK FOR NORMAL CONNECTED WITH A SUSPICIOUS
            
            int a = x[0];
            int b = x[1];

            if(!suspicious[a] && suspicious[b]){    // if a is NORMAL (not suspicious) but b is (in any possible 2D int)
                
                vector<int> ans;

                for(int i = 0; i < n; i++){
                    ans.push_back(i);               // then return all the elements as it is
                }
                
                return ans;
            }

        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!suspicious[i]){                    // otherwise remove all suspicious methods (indirectly keep only NORMAL methods)
                ans.push_back(i);
            }
        }
        return ans;
    }
};
