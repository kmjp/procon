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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,18> bt;
int dp[1<<10];
string A[101010];
int B[101010];

class Solution {
public:
	int hoge(int L1,int R1,int L2,int R2) {
		if(R1<=L1||R2<=L2) return 0;
		
		ll ab=0,ba=0;
		int i;
		for(i=L1;i<R1;i++) bt.add(B[i],1);
		for(i=L2;i<R2;i++) ba+=bt(1<<17)-bt(B[i]);
		for(i=L1;i<R1;i++) bt.add(B[i],-1);
		return ba;
	}
	int hoge(int L,int R,int cur) {
		if(R-L<=1) return 0;
		int Ls[11],Rs[11];
		int i,x,y;
		FOR(i,11) Ls[i]=1<<20,Rs[i]=0;
		
		int ret=0;
		int v=-1;
		for(i=L;i<R;i++) {
			if(A[i].size()==cur) {
				v=B[i];
			}
			else {
				chmin(Ls[A[i][cur]-'a'],i);
				chmax(Rs[A[i][cur]-'a'],i+1);
				if(B[i]<v) ret++;
			}
		}
		
		
		FOR(i,10) if(Ls[i]<Rs[i]) ret+=hoge(Ls[i],Rs[i],cur+1);
		int num=0;
		FOR(i,10) if(Ls[i]<Rs[i]) {
			Ls[num]=Ls[i];
			Rs[num]=Rs[i];
			num++;
		}
		int C[10][10];
		FOR(x,num) FOR(y,x) {
			C[x][y]=hoge(Ls[x],Rs[x],Ls[y],Rs[y]);
			C[y][x]=1LL*(Rs[x]-Ls[x])*(Rs[y]-Ls[y])-C[x][y];
		}
		int mask;
		FOR(mask,1<<num) dp[mask]=1<<30;
		dp[0]=ret;
		FOR(mask,1<<num) FOR(i,num) if((mask&(1<<i))==0) {
			int cur=dp[mask];
			FOR(x,num) if(mask&(1<<x)) cur+=C[x][i];
			chmin(dp[mask|(1<<i)],cur);
		}
		
		
		return dp[(1<<num)-1];
		
	}

    int minInversions(vector<string>& words, vector<int>& target) {
		vector<pair<string,int>> V;
		int i;
		FOR(i,words.size()) V.push_back({words[target[i]],i});
		sort(ALL(V));
		FOR(i,words.size()) {
			A[i]=V[i].first;
			B[i]=V[i].second;
		}
		return hoge(0,words.size(),0);
        
    }
};