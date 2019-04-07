/*Q.)

 Cherry Pickup


Tags:Leetcode,dp

*/

#define inf 100000 
int g[100][100];
int n,m;
    
class Solution {
public:

    int cost( int row1, int col1, int row2, int col2) 
    {  
        if (row1 == row2 && col1 == col2) {  
            if (g[row1][col1] == 1) 
                return 1;
            return 0; 
        } 

        int ans = 0;  
        if (g[row1][col1] == 1) 
            ans++; 
        if (g[row2][col2] == 1) 
            ans++; 

        return ans; 
    } 
    
    
    int dp[101][101][101];
    
    int solve( int row1, int col1, int row2){
        int col2 = (row1 + col1) - (row2); 
         if (row1 == n - 1 && col1 == m - 1 && row2 == n - 1 && col2 == m - 1) 
        return cost(row1,col1,row2,col2); 
        
        if (row1 >= n || col1 >= m ||  row2 >= n || col2 >= m) 
        return -1 * inf; 
        
        
        if (dp[row1][col1][row2] != -1) 
        return dp[row1][col1][row2]; 
        
         int ch1 = -1 * inf, ch2 = -1 * inf; 
         int ch3 = -1 * inf, ch4 = -1 * inf; 

        int k=cost(row1, col1, row2, col2);
        
        if (g[row1][col1 + 1] != -1 &&  g[row2 + 1][col2] != -1) 
        ch1 =k + solve(row1, col1 + 1, row2 + 1); 
  
        if (g[row1][col1 + 1] !=-1 && g[row2][col2 + 1] != -1) 
          ch2 = k +  solve( row1, col1 + 1, row2); 
 
        if (g[row1 + 1][col1] != -1 && g[row2][col2 + 1] != -1) 
         ch3 = k +  solve( row1 + 1, col1, row2); 
        
        if (g[row1 + 1][col1] != -1 &&  g[row2 + 1][col2] != -1) 
          ch4 = k + solve( row1 + 1, col1, row2 + 1); 

        return dp[row1][col1][row2] = max(max(ch1,ch2), max(ch3, ch4)); 
  
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        memset(dp, -1 , sizeof(dp));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                g[i][j]=grid[i][j];
            }
        }
        int ans= solve(0,0,0);
        if(ans<0)return 0;
        else return ans;
    }
};
