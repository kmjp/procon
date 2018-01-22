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

int A,B;
int C[12][12];
int D[101][101];
int DX[12][12];
int DY[12][12];
int NV;
int V[303][303];

int K=100;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(V);
	
	cin>>A>>B;
	for(x=1;x<=A;x++) {
		for(y=1;y<=B;y++) {
			cin>>C[x][y];
		}
	}
	
	vector<int> Xs,Ys;
	NV=1;
	Xs.push_back(NV);
	FOR(i,K) {
		V[NV][NV+1]=-2;
		NV++;
		Xs.push_back(NV);
	}
	NV++;
	Ys.push_back(NV);
	FOR(i,K) {
		V[NV+1][NV]=-3;
		NV++;
		Ys.push_back(NV);
	}
	
	for(x=0;x<=K;x++) {
		for(y=0;y<=K;y++) {
			int ret=0;
			for(i=1;i<=A;i++) {
				for(j=1;j<=B;j++) {
					ret=max(ret,C[i][j]-x*i-y*j);
				}
			}
			D[x][y]=V[Xs[x]][Ys[y]]=ret;
		}
	}
	
	for(i=1;i<=A;i++) {
		for(j=1;j<=B;j++) {
			int mi=1010;
			for(x=0;x<=K;x++) {
				for(y=0;y<=K;y++) {
					mi=min(mi,x*i+j*y+D[x][y]);
				}
			}
			if(mi!=C[i][j]) return _P("Impossible\n");
			
		}
	}
	
	
	
	int cnt=0;
	FOR(x,303) FOR(y,303) if(V[x][y]!=-1) cnt++;
	cout<<"Possible"<<endl;
	cout<<NV<<" "<<cnt<<endl;
	FOR(x,303) FOR(y,303) if(V[x][y]!=-1) {
		cout<<x<<" "<<y<<" ";
		if(V[x][y]==-2) cout<<"X"<<endl;
		if(V[x][y]==-3) cout<<"Y"<<endl;
		if(V[x][y]>=0) cout<<V[x][y]<<endl;
	}
	cout<<Xs[0]<<" "<<Ys[0]<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
