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

ll dist[404][404];
int GX,GY,N,F;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,402) FOR(j,402) dist[i][j]=1LL<<60;
	dist[0][0]=0;
	
	cin>>GX>>GY>>N>>F;
	while(N--) {
		cin>>i>>j>>r;
		for(x=200;x>=0;x--) {
			for(y=200;y>=0;y--) {
				dist[y+j][x+i]=min(dist[y+j][x+i],dist[y][x]+r);
			}
		}
	}
	ll mi=1LL<<60;
	FOR(x,GX+1) FOR(y,GY+1) mi=min(mi,dist[y][x]+((GX-x)+(GY-y))*F);
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
