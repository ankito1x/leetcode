class Solution {
public:
    
    string maskVowels(const string &word) {
        string res;
        for (char c : word) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                res.push_back('*');
            else
                res.push_back(lower);
        }
        return res;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactWords(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap;   // lowercase -> first word
        unordered_map<string, string> vowelMap;  // masked vowels -> first word

        
        for (const string &word : wordlist) {
            string lower = word;
            for (auto &c : lower) c = tolower(c);

            if (!caseMap.count(lower))
                caseMap[lower] = word;

            string masked = maskVowels(word);
            if (!vowelMap.count(masked))
                vowelMap[masked] = word;
        }

        vector<string> result;
        for (const string &q : queries) {
            if (exactWords.count(q)) {
                result.push_back(q);
                continue;
            }

            string lowerQ = q;
            for (auto &c : lowerQ) c = tolower(c);

            if (caseMap.count(lowerQ)) {
                result.push_back(caseMap[lowerQ]);
                continue;
            }

            string maskedQ = maskVowels(q);
            if (vowelMap.count(maskedQ)) {
                result.push_back(vowelMap[maskedQ]);
                continue;
            }

            result.push_back("");
        }
        return result;
    }
};
