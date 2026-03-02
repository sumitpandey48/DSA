class Solution {
public:
    string trimTrailingVowels(string s) {
        while (s.size() && (s.back() == 'a' || s.back() == 'e' || s.back() =='i' || s.back() == 'o' || s.back() == 'u')) {
            s.pop_back();
        }
        return s;
    }
};