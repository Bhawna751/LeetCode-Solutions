class Solution {
public:
    int smallestNumber(int n) {
    return pow(2, floor(log2(n) + 1)) - 1;
}
};