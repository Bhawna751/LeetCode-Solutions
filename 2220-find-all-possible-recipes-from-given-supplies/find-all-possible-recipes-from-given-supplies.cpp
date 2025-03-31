class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        set<string> available(supplies.begin(), supplies.end());  
        unordered_map<string, vector<string>> needs;  

        for (int i = 0; i < recipes.size(); i++)
            needs[recipes[i]] = ingredients[i];

        bool updated = true;
        while (updated) {  
            updated = false;
            for (auto& r : recipes) {
                if (available.count(r)) continue;  
                
                bool canMake = true;
                for (string& ing : needs[r]) {
                    if (!available.count(ing)) {  
                        canMake = false;
                        break;
                    }
                }
                
                if (canMake) {
                    available.insert(r);  
                    updated = true;
                }
            }
        }
        
        vector<string> res;
        for (auto& r : recipes) if (available.count(r)) res.push_back(r);
        return res;
    }
};