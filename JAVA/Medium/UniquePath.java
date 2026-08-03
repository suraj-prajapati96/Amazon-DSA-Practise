
class UniquePath{

    static int solve(int i, int j, int m, int n, int [][] memo){
        if(i>=m || j>=n) return 0;
        if(i == m-1 && j==n-1) return 1;
        if(memo[i][j]!=-1){
            return memo[i][j];
        }else{
            return memo[i][j] = solve(i+1,j,m,n,memo) + solve(i,j+1,m,n,memo);
        }
    }

    static int uniquePath(int m,int n){
        int [][] memo = new int[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                memo[i][j] = -1;
            }
        }
        return solve(0,0,m,n,memo);
    }
    public static void main(String args[]){
        int m = 3, n=2;
        System.out.println(uniquePath(m,n));
    }
}