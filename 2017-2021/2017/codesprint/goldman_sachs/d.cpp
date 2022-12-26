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

int N,Q;
int T[101010],P[101010];

vector<pair<int,int>> A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>T[i];
	FOR(i,N) cin>>P[i];
	A.push_back({-1,-1});
	FOR(i,N) if(P[i]>A.back().first) A.push_back({P[i],T[i]});
	B.push_back({T[N-1],P[N-1]});
	for(i=N-2;i>=0;i--) {
		P[i]=max(P[i],P[i+1]);
		B.push_back({T[i],P[i]});
	}
	reverse(ALL(B));
	while(Q--) {
		cin>>i>>x;
		if(i==1) {
			y = lower_bound(ALL(A),make_pair(x,0))-A.begin();
			if(y==A.size()) cout<<-1<<endl;
			else cout<<A[y].second<<endl;
		}
		else {
			y = lower_bound(ALL(B),make_pair(x,0))-B.begin();
			if(y==B.size()) cout<<-1<<endl;
			else cout<<B[y].second<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
