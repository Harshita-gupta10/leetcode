class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {
                                            {0,1}, // East
                                            {1,0}, // South
                                            {0, -1}, // West
                                            {-1, 0} // North
                                        };
        int total = rows * cols;
        int steps = 0;
        int dir = 0;

        vector<vector<int>> result;
        result.push_back({rStart, cStart});
        int count = 1;

        int r = rStart;
        int c = cStart;

        while(count < total)
        {
            if(dir == 0 || dir == 2) steps++;
            
            for(int i = 0; i < steps; i++)
            {
                r += directions[dir][0];
                c += directions[dir][1];
                
                if(r >= 0 && r < rows && c >= 0 && c < cols)
                {
                    result.push_back({r, c});
                    count++;
                }
            }
            dir = (dir+1) % 4;
        }
        return result;
    }
};