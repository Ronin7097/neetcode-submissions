class Solution {
    unordered_map<char, vector<char>> adj;
    unordered_map<char, int> indeg;

    pair<pair<char, char>, bool> edges(string &a, string &b) {
        int n = min(a.size(), b.size());

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i])
                return {{a[i], b[i]}, true};
        }

        // Invalid case: "abcd" before "abc"
        if (a.size() > b.size())
            return {{'/', '/'}, false};

        return {{'/', '/'}, true};
    }

public:
    string foreignDictionary(vector<string> &words) {
        int n = words.size();

        // Create all characters
        for (string &word : words) {
            for (char c : word) {
                adj[c];
                indeg[c] = 0;
            }
        }

        // Build graph
        for (int i = 1; i < n; i++) {
            auto [edge, valid] = edges(words[i - 1], words[i]);

            if (!valid)
                return "";

            auto [a, b] = edge;

            if (a != '/') {
                adj[a].push_back(b);
                indeg[b]++;
            }
        }

        queue<char> q;

        for (auto &[node, degree] : indeg) {
            if (degree == 0)
                q.push(node);
        }

        string ans;

        while (!q.empty()) {
            char node = q.front();
            q.pop();

            ans.push_back(node);

            for (char next : adj[node]) {
                indeg[next]--;

                if (indeg[next] == 0)
                    q.push(next);
            }
        }

        // Cycle exists
        if (ans.size() != indeg.size())
            return "";

        return ans;
    }
};