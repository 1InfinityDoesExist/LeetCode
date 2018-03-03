int rowHash[9][9];
int colHash[9][9];
int boardHash[3][3][9];
class Solution {
public:
    bool SolveSudoku(vector<vector<char> > &board, int position)
    {
        if(position >= 9 * 9)
        {
            return true;
        }
        int row = position/9;
        int col = position%9;
        if(board[row][col] != '.')
        {
            return SolveSudoku(board, position+1);
        }
        for(int num = 0; num < 9 ;num++)
        {
            if(rowHash[row][num] != 1 && colHash[col][num] != 1 && boardHash[row/3][col/3][num] != 1)
            {
                board[row][col] = '1' + num;
                rowHash[row][num] = 1;
                colHash[col][num] = 1;
                boardHash[row/3][col/3][num] = 1;
                if(SolveSudoku(board, position+1))
                {
                    return true;
                }
                board[row][col] = '.';
                rowHash[row][num] = 0;
                colHash[col][num] = 0;
                boardHash[row/3][col/3][num] = 0;

            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(rowHash, 0, sizeof(rowHash));
        memset(colHash, 0, sizeof(colHash));
        memset(boardHash, 0, sizeof(boardHash));

        for(int row = 0; row < 9; row++)
        {
            for(int col = 0; col < 9; col++)
            {
                if(board[row][col] != '.' )
                {
                    int num = board[row][col] - '1';
                    rowHash[row][num] = 1;
                    colHash[col][num] = 1;
                    boardHash[row/3][col/3][num] = 1;
                }
            }
        }
        SolveSudoku(board, 0);
    }
};
