int Solution::solve(vector<int> &A, int B) {
    bool dp[A.size()+1][B+1];
    int n=A.size();
    memset(dp,false,sizeof(dp));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=B;j++){
            if(i==0)
                dp[i][j]=false;
            if(j==0)
                dp[i][j]=true;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=B;j++){
            if(j>=A[i-1])
                dp[i][j]=dp[i-1][j-A[i-1]]||dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    if(dp[n][B])
        return 1;
    return 0;
}
