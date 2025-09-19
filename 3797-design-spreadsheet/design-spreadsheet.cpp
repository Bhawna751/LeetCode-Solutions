class Spreadsheet {
public:
    vector<vector<int>> spreadsheet;
    Spreadsheet(int rows) {
        spreadsheet = vector<vector<int>>(rows+1,vector<int>(26));
    }
    
    void setCell(string cell, int value) {
        int y= cell[0]-'A';
        int x= stoi(cell.substr(1));
        spreadsheet[x][y] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell,0);
    }
    int helper(const string& cell){
        if(isdigit(cell[0])) return stoi(cell);
        int y = cell[0]-'A';
        int x = stoi(cell.substr(1));
        return spreadsheet[x][y];
    }
    int getValue(string formula) {
        formula = formula.substr(1);
        size_t sign = formula.find('+');
        return helper(formula.substr(0,sign)) + helper(formula.substr(sign+1));
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */