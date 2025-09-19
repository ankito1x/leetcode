class Spreadsheet {
public:
    // Hashmap to store only set cells
    unordered_map<string, int> cells;

    Spreadsheet(int rows) {
        // rows not really used here, since problem guarantees valid input
    }
    
    void setCell(string cell, int value) {
        cells[cell] = value;
    }
    
    void resetCell(string cell) {
        cells.erase(cell); // if not present, nothing happens
    }
    
    int getValue(string formula) {
        // Formula always starts with '=' and is in the form "=X+Y"
        string expr = formula.substr(1); // remove '='
        int plusPos = expr.find('+');
        string left = expr.substr(0, plusPos);
        string right = expr.substr(plusPos + 1);

        return getVal(left) + getVal(right);
    }
    
private:
    int getVal(const string& token) {
        // If token starts with a digit → it's a number
        if (isdigit(token[0])) {
            return stoi(token);
        }
        // Otherwise, it's a cell reference
        if (cells.count(token)) return cells[token];
        return 0;
    }
};
