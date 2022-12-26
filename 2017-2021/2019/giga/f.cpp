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

int H,W,N;
int A[5050][5050];
int S[5050][5050];
int D[5050][5050];
int L[5050],R[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		cin>>y>>x;
		A[y-1][x-1]=1;
	}
	FOR(x,W+1) S[0][x]=x+1;
	FOR(y,H) {
		FOR(x,W) S[y+1][x+1]=S[y+1][x]+A[y][x];
	}
	FOR(x,W) {
		for(y=H-1;y>=0;y--) if(A[y][x]==0) D[y][x]=D[y+1][x]+1;
	}
	ll ret=0;
	FOR(y,H) {
		vector<pair<int,int>> V;
		V.push_back({-1,W});
		for(x=W-1;x>=0;x--) {
			r=D[y][x];
			while(V.back().first>=r) V.pop_back();
			R[x]=V.back().second;
			V.push_back({r,x});
		}
		V.clear();
		V.push_back({-1,-1});
		FOR(x,W) {
			r=D[y][x];
			while(V.back().first>r) V.pop_back();
			L[x]=V.back().second;
			V.push_back({r,x});
			if(A[y][x]==0 && (L[x]==-1 || D[y][L[x]]<D[y][x])) {
				if(S[y][R[x]]-S[y][L[x]+1]) ret++;
			}
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
