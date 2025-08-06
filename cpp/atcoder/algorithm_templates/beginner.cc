// Sliding Window ===========================================================================

// FIZED SIZED SLIDING
// Fixed window size k
for (int i = 0; i < n; i++) {
    window_sum += a[i];
    if (i >= k - 1) {
        // do something with window_sum
        window_sum -= a[i - k + 1];
    }
}

// SHRINKING SLIDING WINDOW
int l = 0;
for (int r = 0; r < n; r++) {
    // expand window: include a[r]

    while (/* window is invalid */) {
        // shrink window from left
        l++;
    }

    // now window [l, r] is valid
}

// Prefix Sums ===========================================================================
//BASIC PREFIX SUM
vector<long> prefix(n + 1, 0);
for (int i = 0; i < n; i++) {
    prefix[i+1] = prefix[i] + a[i];
}

// sum of subarray [l, r] = prefix[r+1] - prefix[l]

// TARGET SUBARRAYS WITH HASHMAP
unordered_map<long, int> freq;
freq[0] = 1;
long sum = 0, count = 0;

for (int x : a) {
    sum += x;
    count += freq[sum - k];
    freq[sum]++;
}

// Hashmaps ===========================================================================

//COUNT ELEMENTS
unordered_map<int, int> count;
for (int x : a) {
    count[x]++;
}

// COMPARE FREQUENCIES
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;
    for (char c : t) freq[c - 'a']--;
    for (int f : freq) if (f != 0) return false;
    return true;
}


// Recursive DP ===========================================================================

//GENERAL
unordered_map<string, int> memo;

int dp(int i, int j, const vector<int>& a) {
    string key = to_string(i) + "," + to_string(j);
    if (memo.count(key)) return memo[key];

    // base case
    if (i >= a.size()) return 0;

    // recurse
    int res = max(dp(i + 1, j, a), dp(i + 2, j, a) + a[i]);
    return memo[key] = res;
}

// 1D MEMO
vector<int> memo(n + 1, -1);

int climb(int i) {
    if (i <= 1) return 1;
    if (memo[i] != -1) return memo[i];
    return memo[i] = climb(i - 1) + climb(i - 2);
}

// Binary Search ===========================================================================

// STANDARD
int binarySearch(vector<int>& a, int target) {
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == target) return mid;
        else if (a[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// SEARCH ON ANSWER 
bool isValid(int x) {
    // define validity of candidate answer x
}

int l = 1, r = 1e9, ans = -1;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (isValid(mid)) {
        ans = mid;
        r = mid - 1;  // or l = mid + 1 for max
    } else {
        l = mid + 1;
    }
}



