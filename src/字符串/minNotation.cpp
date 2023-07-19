int minNotation(const vector<int> &s) {
    int n = s.size();
    int i = 0, j = 1;
    for (int k = 0; k < n && i < n && j < n;) {
        if (s[(i + k) % n] == s[(j + k) % n]) k++;
        else {
            if (s[(i + k) % n] > s[(j + k) % n]) i = i + k + 1;
            else j = j + k + 1;
            if (i == j) i++;
            k = 0;
        }
    }
    return min(i, j);
}