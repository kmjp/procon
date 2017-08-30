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

int M;
int P[21][300005],D[300005];

set<int> L;
int X,Y,dia;

int dist(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]];  // dist
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) {
		cin>>P[0][i+1];
		P[0][i+1]--;
		D[i+1]=D[P[0][i+1]]+1;
	}
	M++;
	FOR(i,19) FOR(x,M) P[i+1][x]=P[i][P[i][x]];
	
	cout<<2<<endl;
	X=0,Y=1;
	dia=1;
	L.insert(0);
	L.insert(1);
	
	int ret=2;
	for(i=2;i<M;i++) {
		L.erase(P[0][i]);
		
		int dx=dist(X,i);
		int dy=dist(Y,i);
		
		if(dx<=dia && dy<=dia) {
			if(dx==dia || dy==dia) L.insert(i);
		}
		else {
			if(dy>dia) swap(X,Y), swap(dx,dy);
			dia=dx;
			Y=i;
			set<int> L2=L;
			L.clear();
			FORR(r,L2) if(dist(r,Y)==dia) L.insert(r);
			L.insert(X);
			L.insert(Y);
		}
		
		cout<<L.size()<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
