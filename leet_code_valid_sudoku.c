bool isValidSudoku(char** board, int boardSize, int* boardColSize) {

  int i,j,k,q;

  boardSize=9;

  for(i=0;i<boardSize;i++){
    for(j=0;j<boardSize;j++){
      if(board[i][j]!='.'){
        for(k=j+1;k<boardSize;k++){
          if(board[i][k]!='.'){
            if(board[i][k]==board[i][j]) return false;
          }
        }

        for(q=i+1;q<boardSize;q++){
          if(board[q][j]!='.'){
            if(board[q][j]==board[i][j]) return false;
          }
        }

          int inou=i%3;
          int jnou=j%3;
          for(k=i-inou;k<i-inou+3;k++)
            for(q=j-jnou;q<j-jnou+3;q++){

              if(k!=i && q!=j)
              {
                if(board[k][q]==board[i][j])
                  return false;
              }
            }
      }
    }
  }

  return true;
}
