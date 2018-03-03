class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        map<char, bool> col;
        map<char, bool> row;
        map<char, bool> block;

        for(int iter = 0; iter < 9; iter++)
        {
            row.clear();
            col.clear();
            for(int jter = 0; jter < 9; jter++)
            {
                if(board[iter][jter] != '.')
                {
                    if(col[board[iter][jter]])
                    {
                        return false;
                    }
                    else
                    {
                        col[board[iter][jter]] = true;
                    }
                }
                if(board[jter][iter] != '.')
                {
                    if(row[board[jter][iter]])
                    {
                        return false;
                    }
                    else
                    {
                        row[board[jter][iter]] = true;
                    }
                }
            }
        }

            for(int iter = 0; iter < 9; iter = iter+3)
            {
                for(int jter = 0; jter < 9; jter = jter+3)
                {
                    block.clear();
                    for(int i = iter ; i < iter+3; i++)
                    {
                        for(int j = jter ; j < jter+3; j++)
                        {
                            if(board[i][j] != '.')
                            {
                                if(block[board[i][j]])
                                {
                                    return false;
                                }
                                else
                                {
                                    block[board[i][j]] = true;
                                }
                            }
                        }
                    }
                }
            }

        return true;
    }
};
