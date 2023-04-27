

int numSquares(int n){
	int dp[n+1];
	dp[0] = 0;

	for (int i=1; i<n+1; ++i){
		dp[i] = i;
		for (int j=2; j*j<=i; ++j){
			dp[i] = 1+dp[i-(j*j)] < dp[i] ? 1+dp[i-(j*j)] : dp[i];
		}
	}

	return dp[n];

}
