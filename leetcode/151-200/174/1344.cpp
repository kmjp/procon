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


int dp[1010];

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
		int N=arr.size();
        vector<pair<int,int>> V;
        int i;
        FOR(i,N) {
			V.push_back({arr[i],i});
			dp[i]=1;
		}
        sort(ALL(V));
        reverse(ALL(V));
        int ma=1;
        FORR(v,V) {
			i=v.second;
			ma=max(ma,dp[i]);
			cout<<i<<" "<<arr[i]<<" "<<dp[i]<<endl;
			int pre=-1;
			for(int j=i+1;j<N && j-i<=d;j++) {
				if(arr[j]>=arr[i]) break;
				dp[j]=max(dp[j],dp[i]+1);
			}
			pre=-1;
			for(int j=i-1;j>=0 && i-j<=d;j--) {
				if(arr[j]>=arr[i]) break;
				dp[j]=max(dp[j],dp[i]+1);
			}
		}
        return ma;
        
    }
};

