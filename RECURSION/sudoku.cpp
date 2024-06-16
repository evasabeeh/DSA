class Solution {
public:
    bool check(vector<vector<char>>& board, int x, int y, int val){
        for(int i=0;i<9;i++){
            if(board[x][i]==val||board[i][y]==val)       //row or col
            return false;
            if(board[3*(x/3)+(i/3)][3*(y/3)+(i%3)]==val) //box
            return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char val='1';val<='9';val++){
                        if(check(board, i, j, val)){
                            board[i][j]=val;
                            bool further=solve(board);

                            if(further==true)
                            return true;
                            else
                            board[i][j]='.';           //backtrack
                        }
                    }
                    return false;               //when no valid digit is found
                }
            }
        }
        return true;        //board is filled
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};