class Solution {
public:
    void dfs(vector<vector<int>>& stones,int index,vector<bool>& visited) {
        visited[index]=true;

        for(int i=0;i<stones.size();i++) {
            int row = stones[index][0];
            int col = stones[index][1];

            if(visited[i]==false &&
               ((stones[i][0] == row) || (stones[i][1] == col))) {
                dfs(stones, i, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        vector<bool> visited(n,false);

        int group=0;
        for(int i=0;i<n;i++) {
            if(visited[i]) continue;
            dfs(stones,i,visited);
            group++;
        }
        return (n-group);
    }
};