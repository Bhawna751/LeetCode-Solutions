class Solution {
public:
    void lpsArray(string& needle, int m, vector<int>& lps) {
        // Length of the previous longest prefix suffix
        int len = 0;
        // lps[0] is always 0
        lps[0] = 0;
        // loop calculates lps[i] for i = 1 to m-1
        int i = 1;
        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else // (needle[i] != needle[len])
            {
                if (len != 0) {
                    len = lps[len - 1];
                } else // if (len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        int m = needle.length(), n = haystack.length();

        // Create lps[] that will hold the longest prefix suffix
        // values for needletern
        vector<int> lps(m);

        vector<int> result;

        // Preprocess the needletern (calculate lps[] array)
        lpsArray(needle, m, lps);

        int i = 0; // index for haystack
        int j = 0; // index for needle
        while (i < n) {
            if (needle[j] == haystack[i]) {
                j++;
                i++;
            }

            if (j == m) {

                return i - j;
            }

            // mismatch after j matches
            else if (i < n && needle[j] != haystack[i]) {
                // Do not match lps[0..lps[j-1]] characters, they will match
                // anyway
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
};