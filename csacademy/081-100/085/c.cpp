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

int N,A,B;
int X[51];
int p2[53],p3[53];

int to[53][53];
pair<int,int> P[53];

void hoge(int x,int y) {
	int cur=X[x];
	int i;
	FOR(i,p2[x]-p2[y]) cur/=2, cout<<" "<<cur;
	FOR(i,p3[y]-p3[x]) cur*=3, cout<<" "<<cur;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	X[0]=A;
	X[N+1]=B;
	FOR(i,N) cin>>X[i+1];
	
	int G=__gcd(A,B);
	FOR(i,N) G=__gcd(G,X[i+1]);
	
	FOR(i,N+2) {
		x=X[i]/G;
		while(x%2==0) p2[i]++,x/=2;
		while(x%3==0) p3[i]++,x/=3;
		if(x!=1) return _P("-1\n");
	}
	
	FOR(x,N+2) FOR(y,N+2) if(x!=y) to[x][y]=(p2[x]>=p2[y])&&(p3[x]<=p3[y]);
	FOR(x,N+2) FOR(y,N+2) if(x!=y && to[x][y]==0 && to[y][x]==0) return _P("-1\n");
	FOR(x,N+2) {
		FOR(y,N+2) P[x].first+=to[y][x];
		P[x].second=x;
	}
	sort(P,P+N+2);
	if(P[0].second!=0 || P[N+1].second!=N+1) return _P("-1\n");
	cout<<X[P[i].second];
	FOR(i,N+1) hoge(P[i].second,P[i+1].second);
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
