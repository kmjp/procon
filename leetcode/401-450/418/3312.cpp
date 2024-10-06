#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


ll C[505050];
ll P[505050];
ll S[505050];

map<int,vector<int>> M;

vector<int> enumdiv(int n) {
	
	if(M.count(n)==0) {
		vector<int> S;
		for(int i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
		M[n]=S;
	}
	
	return M[n];
}

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
		int i,j;
		FOR(i,50505) C[i]=P[i]=0;
		FORR(a,nums) {
			auto V=enumdiv(a);
			FORR(v,V) P[v]+=C[v]++;
		}
		for(i=50000;i>=1;i--) {
			for(j=i*2;j<=50000;j+=i) P[i]-=P[j];
		}
		for(i=1;i<=50000;i++) S[i]=S[i-1]+P[i];
		
		
		vector<int> R;
		FORR(q,queries) {
			R.push_back(lower_bound(S,S+50001,q+1)-S);
			
		}
		return R;
		
        
    }
};

