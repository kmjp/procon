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
pair<int,int> P[101];
pair<int,int> Q[101];
int A[101];
vector<pair<int,int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i].first;
		P[i].second=i;
		Q[i]=P[i];
	}
	sort(P,P+N);
	FOR(i,N) {
		for(x=i;x<N;x++) if(Q[x].second==P[i].second) break;
		if(i!=x) {
			swap(Q[x],Q[i]);
			V.push_back({i,x});
		}
	}
	_P("%d\n",V.size());
	FORR(r,V) _P("%d %d\n",r.first,r.second);
	fflush(stdout);
	cin>>x;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
