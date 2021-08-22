typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

//-------------------------------------------------------

int dp[3535][3535];
const int mo=1000000007;

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<(s.size()+3)/2;i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

class Solution {
public:
    int numberOfCombinations(string num) {
        int n=num.size();
        
        if(num[0]=='0') return 0;
        int i,j;
        FOR(i,n+1) FOR(j,n+1) dp[i][j]=0;
        dp[0][1]=1;
        
        ll ret=0;
        FOR(i,n) {
			if(num[i]=='0') continue;
			string S=num.substr(i);
			vector<int> A=Zalgo(S);
			
			for(int len=1;i+len<=n;len++) {
				(dp[i][len]+=dp[i][len-1]);
				if(dp[i][len]>=mo) dp[i][len]-=mo;
				if(i+len+len>n) continue;
				if(dp[i][len]==0) continue;
				
				if(A[len]>=len) {
					(dp[i+len][len]+=dp[i][len]);
					if(dp[i+len][len]>=mo) dp[i+len][len]-=mo;
				}
				else {
					int x=A[len];
					if(S[x]<=S[x+len]) {
						(dp[i+len][len]+=dp[i][len]);
						if(dp[i+len][len]>=mo) dp[i+len][len]-=mo;
					}
					else {
						(dp[i+len][len+1]+=dp[i][len]);
						if(dp[i+len][len+1]>=mo) dp[i+len][len+1]-=mo;
					}
				}
			}
			ret+=dp[i][n-i];
		}
        
        
        return ret%mo;
    }
};
