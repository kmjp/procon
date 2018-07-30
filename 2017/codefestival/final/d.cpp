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

int H[5050],P[5050],V[5050];

ll mi[5002][5002];

bool cmp(int l,int r) {
	return H[r]-P[l]>H[l]-P[r];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>H[i]>>P[i];
		V[i]=i;
	}
	
	FOR(x,N+1) FOR(y,N+1) mi[y][x]=1LL<<60;
	sort(V,V+N,cmp);
	
	mi[0][0]=0;
	int ma=0;
	FOR(x,N) {
		FOR(y,N+1) mi[x+1][y]=mi[x][y];
		FOR(y,N) if(mi[x][y]<=H[V[x]]) mi[x+1][y+1]=min(mi[x+1][y+1],mi[x][y]+P[V[x]]), ma=max(ma,y+1);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
