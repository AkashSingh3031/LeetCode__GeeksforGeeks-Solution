class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int y = matrix.size(), x = matrix[0].size(), answer = 0;
        vector<vector<int>> a(y,vector<int>(x)), b(y,vector<int>(x));

        for(int j = 0; j != x; j++)
          for(int i = y - 1, k = 0; i >= 0; i--)
            if(matrix[i][j] == '1') a[i][j] = ++k;
            else a[i][j] = k = 0;

        for(int i = 0; i != y; i++)
          for(int j = x - 1, k = 0; j >= 0; j--)
            if(matrix[i][j] == '1') b[i][j] = ++k;
            else b[i][j] = k = 0;

        for(int i = 0; i != y; i++)
          for(int j = 0; j != x; j++){
            int Y = a[i][j], X = b[i][j];
            for(int w = j + 1, lim = j + X; w < lim; w++)
              if(Y > a[i][w]) {answer = max(answer, Y * (w - j)); Y = a[i][w];}

            answer = max(answer, Y * X);
          }

        return answer;
    }
};