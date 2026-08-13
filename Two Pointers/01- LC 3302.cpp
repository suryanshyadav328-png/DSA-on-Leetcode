class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[j] = position in word1 where word2[j]
        // can be matched while matching the rest after it
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        vector<int> ans;

        bool mismatch = false;
        j = 0;

        for (i = 0; i < n && j < m; i++) {

            // Exact match: take it
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use our one mismatch
            else if (!mismatch &&
                     (j == m - 1 || i < last[j + 1])) {

                ans.push_back(i);
                mismatch = true;
                j++;
            }
        }

        if (j != m)
            return {};

        return ans;
    }
};
