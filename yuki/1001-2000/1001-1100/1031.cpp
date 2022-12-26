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
int P[101010];
int L[101010][21],R[101010][21];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<int,int>> cand;
	FOR(i,N) {
		cin>>P[i+1];
		cand.push_back({P[i+1],i+1});
	}
	FOR(j,20) R[N+1][j]=N+1;
	vector<int> V;
	FOR(i,N+1) {
		while(V.size()&&P[V.back()]>P[i]) V.pop_back();
		if(V.size()) L[i][0]=V.back();
		V.push_back(i);
	}
	V.clear();
	V.push_back(N+1);
	for(i=N;i>=1;i--) {
		while(V.size()&&P[V.back()]>P[i]) V.pop_back();
		if(V.size()) R[i][0]=V.back();
		V.push_back(i);
	}
	FOR(i,20) FOR(j,N) L[j+1][i+1]=L[L[j+1][i]][i],R[j+1][i+1]=R[R[j+1][i]][i];
	
	set<int> D;
	D.insert(0);
	D.insert(N+1);
	sort(ALL(cand));
	reverse(ALL(cand));
	ll ret=0;
	FORR(c,cand) {
		x=c.second;
		auto it=D.insert(x).first;
		i=*prev(it);
		j=*next(it);
		int cur=x;
		for(y=19;y>=0;y--) if(R[cur][y]<j) cur=R[cur][y],ret+=1<<y;
		cur=x;
		for(y=19;y>=0;y--) if(L[cur][y]>i) cur=L[cur][y],ret+=1<<y;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
