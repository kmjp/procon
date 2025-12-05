#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

int N,M,Q;
int U[202020],V[202020],P[202020],A[202020],B[202020];

set<int> Es[502020];
int closed[502020];
int nopen;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<int> W;
	FOR(i,M) {
		cin>>U[i]>>V[i];
		W.push_back(U[i]);
		W.push_back(V[i]);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>P[i]>>A[i]>>B[i];
		W.push_back(A[i]);
		if(P[i]==1) {
			W.push_back(B[i]);
		}
	}
	sort(ALL(W));
	W.erase(unique(ALL(W)),W.end());
	FOR(i,M) {
		x=lower_bound(ALL(W),U[i])-W.begin();
		y=lower_bound(ALL(W),V[i])-W.begin();
		Es[x].insert(y);
	}
	nopen=N;
	FOR(i,Q) {
		x=lower_bound(ALL(W),A[i])-W.begin();
		if(P[i]==1) {
			y=lower_bound(ALL(W),B[i])-W.begin();
			if(Es[x].count(y)) {
				Es[x].erase(y);
			}
			else {
				Es[x].insert(y);
			}
		}
		else {
			if(closed[x]==1) {
				nopen++;
			}
			else {
				nopen--;
			}
			closed[x]^=1;
		}
		int ret=nopen;
		if(closed[x]==0) ret--;
		FORR(a,Es[x]) if(closed[a]) ret++;
		cout<<ret<<endl;
	}
			
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
