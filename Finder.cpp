#include "Finder.h"

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    // store index of last prefix
    size_t earliest = 0;
    for (size_t i = 0; i <= s2.size(); i++) {
        size_t found = s1.find(s2.substr(0, i), earliest);
        if (found != string::npos) {
            result.push_back(found);
            earliest = found;
        } else {
            // if prefix cannot be found, no more prefixes can be found
            for (size_t j = i; j <= s2.size(); j++) {
                result.push_back(-1);
            }
            break;
        }
    }

    return result;
}