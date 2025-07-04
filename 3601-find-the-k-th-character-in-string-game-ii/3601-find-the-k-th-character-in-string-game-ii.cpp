class Solution {
public:
    char nextchar(char ch) {
    return (ch == 'z') ? 'a' : ch + 1;
}

char kthCharacter(long long k, vector<int>& operations) {
    int n = operations.size();
    vector<long long> sizes(n + 1);
    sizes[0] = 1;

    int m = n;
    for (int i = 0; i < n; i++) {
        sizes[i + 1] = sizes[i] * 2;
        if (sizes[i + 1] >= k) {
            m = i + 1;
            break;
        }
    }

    char ch = 'a';
    for (int i = m - 1; i >= 0; i--) {
        if (operations[i] == 0) {
            if (k > sizes[i]) {
                k -= sizes[i]; // second half of doubled string
            } // else: k stays the same (came from first half)
        } else {
            if (k > sizes[i]) {
                k -= sizes[i];      // came from transformed part
                ch = nextchar(ch);  // simulate transformation
            } // else: ch stays same
        }
    }
    return ch;
}
};