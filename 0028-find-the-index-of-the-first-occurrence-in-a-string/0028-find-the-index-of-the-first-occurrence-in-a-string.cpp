class Solution {
public:
    int strStr(string h, string n) {
        size_t occ = h.find(n);
        if (occ != string::npos)
            return occ;
        return -1;
    }
};