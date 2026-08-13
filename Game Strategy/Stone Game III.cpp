// class Solution {
// public:

//     int n;
//     vector<int> t;

//     int solve(vector<int>& stones, int i){

//         if(i >= n) return 0;

//         if(t[i] != -1)
//           return t[i];

//         int result = stones[i] - solve(stones, i+1);

//     if(i+1 < n)
//         result = max(result, stones[i] + stones[i+1] - solve(stones, i+2));

//     if(i+2 < n) 
//         result = max(result, stones[i] + stones[i+1] + stones[i+2] - solve(stones, i+3));

//        return t[i] = result;
//     }


//     string stoneGameIII(vector<int>& stones) {
//         n = stones.size();
//         t.resize(n+1, -1);   //O(n)

//         int diff = solve(stones, 0);    //Alice - Bob


//         if(diff < 0)
//             return "Bob";
//         else if(diff > 0)
//             return "Alice";

//         return "Tie";
//     }
// };



//BOTTOM UP APPROACH

class Solution {
public:

    // int solve(vector<int>& stones, int i){

    //     if(i >= n) return 0;

    //     if(t[i] != -1)
    //       return t[i];

    //     int result = stones[i] - solve(stones, i+1);

    // if(i+1 < n)
    //     result = max(result, stones[i] + stones[i+1] - solve(stones, i+2));

    // if(i+2 < n) 
    //     result = max(result, stones[i] + stones[i+1] + stones[i+2] - solve(stones, i+3));

    //    return t[i] = result;
    // }


    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();
        

        int a = 0;  // t[i+1]  variables so tht array is not used
        int b = 0;  //t[i+2]
        int c = 0;   //t[i+3]

        // t.resize(n+1, -1);   //O(n)

        for(int i = n-1; i >= 0; i--){  // last se fist tk loop

            int result = INT_MIN;  // result instead of t[i] to save space n time

            result = max(result, stones[i] - a);

        if(i+2 <= n) 
            result = max(result, stones[i] + stones[i+1] - b);
          
        if(i+1 < n && i+2 < n && i+3 <= n)
            result = max(result, stones[i] + stones[i+1] + stones[i+2] - c);

            c = b;
            b = a;
            a = result;   // bottom up means last se aate ate first me result store ho jayega.

        }
       
       int diff = a;

        if(diff < 0)
            return "Bob";
        else if(diff > 0)
            return "Alice";

        return "Tie";
    }
};
