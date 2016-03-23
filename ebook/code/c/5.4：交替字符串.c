bool isInterleave(string s1, string s2, string s3)
{

	int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
	if (len3 != len1 + len2) {
		return false;
	}
	vector<vector<bool> > dp;
	dp.resize(len1 + 1);
	for (int i = 0; i <= len1; ++i) {
		dp[i].resize(len2 + 1, false);
		for (int j = 0; j <= len2; ++j) {
			dp[i][j] = ((i == 0) && (j == 0)) || (i && dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (j && dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
		}
	}
	return dp[len1][len2];
}
