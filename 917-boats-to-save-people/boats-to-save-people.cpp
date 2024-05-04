const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(), people.end());
        int low = 0, high = n - 1;
        int boats = 0;
        while (low <= high) {
            if (people[low] + people[high] <= limit) {
                boats++;
                low++;
                high--;
            } else {
                boats++;
                high--;
            }
        }
        return boats;
    }
};