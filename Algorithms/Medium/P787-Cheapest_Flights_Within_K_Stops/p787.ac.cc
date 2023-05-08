class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // flights: [[from, to, price], [from, to, price]]
        vector<vector<pair<int, int>>> graph; // graph[from] = vector<pair<to, price>>
        graph.resize(n);
        for (auto flight: flights) {
            const int from = flight[0];
            const int to = flight[1];
            const int price = flight[2];
            graph[from].push_back({to, price});
        }

        vector<int> distance(n, INT_MAX);
        distance[src] = 0; // Initialize the distance of source to zero

        queue<pair<int, pair<int, int>>> q; // pair<stop_count, pair<current_node, price>>
        q.push({0, {src, 0}}); // {stop_count, {source_node, price}}

        while (!q.empty()) {
            pair<int, pair<int, int>> current = q.front();
            q.pop();
            int stop_counts = current.first;           // stop_count
            int current_node = current.second.first;   // current_node
            int current_price = current.second.second; // current_price

            if (stop_counts > k) continue; // If count is larger then limit, don't update anymore

            // Dijkstra
            for (auto pair : graph[current_node]) {
                // pair = {to, price}, current_node = from
                const int to = pair.first;
                const int price = pair.second;

                if (current_price + price < distance[to]) {
                    distance[to] = current_price + price;
                    q.push({stop_counts + 1, {to, distance[to]}});
                }
            }
        }

        if (distance[dst] == INT_MAX) return -1;
        return distance[dst];
    }
};