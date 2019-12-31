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
int D[101],A[101],B[101];
vector<int> E[101];
int in[101];

map<vector<int>,int> memo[101];

int hoge(vector<int> V) {
	int C[10]={};
	vector<int> W(V.size());
	
	int ret=0;
	int i;
	FOR(i,V.size()) W[V[i]]=i;
	FORR(c,W) {
		ret+=C[c];
		for(int x=max(0,c-D[c]);x<=min((int)V.size()-1,c+D[c]);x++) C[x]+=A[c];
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>D[i];
	FOR(i,N) cin>>A[i];
	
	vector<int> V;
	FOR(i,min(7,N)) V.push_back(i);
	
	int ma=0;
	do {
		memo[V.size()][V] = hoge(V);
		ma=max(ma,memo[V.size()][V]);
	} while(next_permutation(ALL(V)));
	
	if(N<=7) return _P("%d\n",ma);
	
	V.push_back(7);
	for(i=7;i<N;i++) {
		do {
			vector<int> pre=V,pos=V;
			x=V.back();
			pre.pop_back();
			FORR(c,pre) if(c>x) c--;
			x=V.front();
			pos.erase(pos.begin());
			FORR(c,pos) if(c>x) c--;
			
			int add=0;
			FOR(y,7) {
				if(V[y]<V[7]) {
					if(D[i-(7-y)]>=7-y) add += A[i-(7-y)];
				}
				if(V[y]>V[7]) {
					if(D[i]>=7-y) add += A[i];
				}
			}
			
			memo[i+1][pos] = max(memo[i+1][pos],memo[i][pre]+add);
			ma=max(ma,memo[i+1][pos]);
		} while(next_permutation(ALL(V)));
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
