#include <bits/stdc++.h>
using namespace std;
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

int N;
vector<int> E[20];
int A[20],B[20];
int AS[20],BS[20];
vector<ll> S[20];
ll memo[19][1<<19];
int tmask[20][20];
int tmask2[20][20];

ll tree_normalize(vector<ll> T) {
	static ll momo[2]={1000000007,1000000009};
	static vector<ll> prim = {79,73,47,7,41,13,17,19,23,29,31,37,43,5,53,59,61,67,71};
	
	sort(ALL(T));
	int id=0,id2=1;
	ll a=1,b=1;
	FORR(r,T) {
		ll h=r>>32, l=r-(h<<32);
		(a+=h*prim[(id++)%prim.size()])%=momo[0];
		(b+=l*prim[(id2++)%prim.size()])%=momo[1];
	}
	return (a<<32)+b;
}

ll hashhash(int cur,int mask) {
	if(memo[cur][mask]<0) {
		vector<ll> v;
		FORR(e,E[cur]) if(mask&(1<<e)) v.push_back(hashhash(e,mask&tmask[cur][e]));
		memo[cur][mask]=tree_normalize(v);
	}
	return memo[cur][mask];
}

int dfsmask(int cur,int pre) {
	if(tmask2[cur][pre]==0) {
		tmask2[cur][pre]=1<<cur;
		FORR(r,E[cur]) if(r!=pre) tmask2[cur][pre] |= dfsmask(r,cur);
	}
	return tmask2[cur][pre];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
		A[i]=x-1;
		B[i]=y-1;
		AS[i]=1<<A[i];
		BS[i]=1<<B[i];
	}
	
	FOR(i,N) tmask[19][i]=dfsmask(i,19);
	FOR(i,N-1) {
		tmask[A[i]][B[i]]=dfsmask(B[i],A[i]);
		tmask[B[i]][A[i]]=dfsmask(A[i],B[i]);
	}
	
	for(int mask=1;mask<1<<N;mask++) {
		
		x = __builtin_popcount(mask);
		
		int ok=0;
		FOR(i,N-1) if((mask&AS[i])&&(mask&BS[i])) ok++;
		if(ok!=x-1) continue;
		vector<ll> T;
		FOR(i,N) if(mask&(1<<i)) T.push_back(hashhash(i,mask));
		S[x].push_back(tree_normalize(T));
	}
	
	int ret=0;
	FOR(x,20) {
		sort(ALL(S[x]));
		S[x].erase(unique(ALL(S[x])),S[x].end());
		ret+=S[x].size();
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
