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


ll dp[1010];
ll C[202][202];

const int NUMC=26;
class Trie {
public:
	vector<vector<int> > V;
	int find(string s) {
		int cur=0;
		FORR(c,s) if((cur=V[cur][c+1])==0) return -1;
		return cur;
	}
	void create(vector<string> S) { // 0 is for backtrack
		V.clear();
		V.push_back(vector<int>(NUMC+2));
		V.back().back()=-1;
		sort(S.begin(),S.end());
		int i;
		FOR(i,S.size()) {
			string s=S[i];
			int cur=0;
			FORR(c,s) {
				if(V[cur][c+1]==0) {
					V.push_back(vector<int>(NUMC+2));
					V[cur][c+1]=V.size()-1;
					V.back().back()=-1;
				}
				cur=V[cur][c+1];
			}
			V[cur][NUMC+1]=i;
		}
	}
};


class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
		unordered_map<string,int> M;
		set<int> S;
		vector<string> V;
		FORR(a,original) {
			FORR(c,a) c-='a';
			V.push_back(a);
		}
		FORR(a,changed) {
			FORR(c,a) c-='a';
			V.push_back(a);
		}
		int id=0;
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		FORR(a,V) M[a]=id++;
		
		Trie tr;
		tr.create(V);
		
		int i,j,x,y,z;
		FOR(x,id) FOR(y,id) C[x][y]=(x==y)?0:1LL<<60;
		FOR(i,cost.size()) C[M[original[i]]][M[changed[i]]]=min(C[M[original[i]]][M[changed[i]]],(ll)cost[i]);
		FOR(z,id) FOR(x,id) FOR(y,id) C[x][y]=min(C[x][y],C[x][z]+C[z][y]);
		
		
		int N=source.size();
		FOR(i,N+1) dp[i]=1LL<<60;
		dp[0]=0;
		FOR(i,N) {
			if(source[i]==target[i]) {
				dp[i+1]=min(dp[i+1],dp[i]);
			}
			int ca=0,cb=0;
			for(j=1;i+j<=N;j++) {
				ca=tr.V[ca][source[i+j-1]-'a'+1];
				cb=tr.V[cb][target[i+j-1]-'a'+1];
				if(ca==0||cb==0) break;
				if(tr.V[ca][27]>=0&&tr.V[cb][27]>=0) {
					dp[i+j]=min(dp[i+j],dp[i]+C[tr.V[ca][27]][tr.V[cb][27]]);
				}
			}
		}
		ll ret=dp[N];
		if(ret>=1LL<<60) ret=-1;
		return ret;
        
    }
};
