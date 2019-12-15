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

int R;
int H[2],W[2],Y[2],X[2];
int L[2][505][505];
int D[2][505][505];
vector<int> V[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R;
	FOR(i,2) {
		cin>>W[i]>>H[i]>>X[i]>>Y[i];
		X[i]--;
		Y[i]--;
		FOR(y,H[i]) FOR(x,W[i]) {
			cin>>L[i][y][x];
			D[i][y][x]=1<<30;
		}
		priority_queue<pair<int,int>> P;
		D[i][Y[i]][X[i]]=1;
		P.push({-1,Y[i]*1000+X[i]});
		while(P.size()) {
			int co=-P.top().first;
			int cy=P.top().second/1000;
			int cx=P.top().second%1000;
			P.pop();
			if(D[i][cy][cx]!=co) continue;
			V[i].push_back(co);
			FOR(j,4) {
				int dd[4]={0,1,0,-1};
				int ty=cy+dd[j];
				int tx=cx+dd[j^1];
				if(ty<0 || ty>=H[i] || tx<0 || tx>=W[i]) continue;
				if(D[i][ty][tx] > max(L[i][ty][tx],co)) {
					D[i][ty][tx] = max(L[i][ty][tx],co);
					P.push({-D[i][ty][tx], ty*1000+tx});
				}
			}
		}
	}
	
	int mi=1<<30;
	for(i=0;i<=R;i++) {
		if(i>V[0].size() || R-i>=V[1].size()) continue;
		int co=0;
		if(i) co+=V[0][i-1];
		if(R-i) co+=V[1][R-i-1];
		mi=min(mi,co);
	}
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
