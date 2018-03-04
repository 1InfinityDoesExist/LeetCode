
#define MOD 1000000000007
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         long long int X = obstacleGrid.size();

        long long int Y = obstacleGrid[0].size();
       // cout << Y <<endl;
         if(obstacleGrid[0][0] == 1)
        {
            return 0;
        }


         if(obstacleGrid[X-1][Y-1] == 1)
        {
            return 0;
        }
        if(obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1)
        {
            return 1;
        }


        //just storing the oblstacle....
        vector<pair<long long int, long long int> > obs;
        for(int iter = 0; iter < X; iter++)
        {
            for(long long int jter = 0; jter < Y; jter++)
            {
                if(obstacleGrid[iter][jter] == 1)
                {
                    obs.push_back(make_pair(iter, jter));
                }
            }
        }



        long long int Grid[X][Y];
        memset(Grid, 0, sizeof(Grid));
        for(long long int iter = 0; iter < obs.size(); iter++)
        {
            pair<int, int> o = obs[iter];
            int _i = o.first;
            int _j = o.second;

            Grid[_i][_j] = -1;
        }



        Grid[0][0] = 1;
        for(long long int jter = 1; jter < Y; jter++)
        {
            if(Grid[0][jter] == -1)
            {
                break;
            }
            else
            {
                Grid[0][jter] = 1LL;
            }
        }

        for(long long int iter = 1; iter < X; iter++)
        {
            if(Grid[iter][0] == -1)
            {
                break;
            }
            else
            {
                Grid[iter][0] = 1LL;
            }
        }


        for(long long int iter = 1; iter < X; iter++)
        {
            for(long long int jter = 1; jter < Y; jter++)
            {
                if(Grid[iter][jter] == -1)
                {
                    continue;
                }
                if(Grid[iter-1][jter] > 0)
                {
                    Grid[iter][jter] = (long long )(Grid[iter][jter] + Grid[iter-1][jter] + MOD)%MOD;
                }
                if(Grid[iter][jter-1] > 0)
                {
                    Grid[iter][jter] = (long long )(Grid[iter][jter] + Grid[iter][jter-1] + MOD)%MOD;
                }
            }
        }



        return (Grid[X-1][Y-1] >= 0 ? Grid[X-1][Y-1] : 0);

    }
};
