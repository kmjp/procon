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

int N,M;
int A[1010][1010];

ll D[2][1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(y,N) {
		FOR(x,M) {
			cin>>A[N-1-y][x];
			D[0][y][x]=D[1][y][x]=1LL<<60;
		}
	}
	priority_queue<pair<ll,int>> Q;
	D[0][0][0]=0;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int id=Q.top().second/1000000;
		int cy=Q.top().second/1000%1000;
		int cx=Q.top().second%1000;
		Q.pop();
		if(cy==N-1) {
			cout<<co<<endl;
			return;
		}
		if(D[id][cy][cx]!=co) continue;
		if(id==0) {
			if(cx&&D[id][cy][cx-1]>co) {
				D[id][cy][cx-1]=co;
				Q.push({-co,id*1000000+cy*1000+cx-1});
			}
			if(cx+1<M&&D[id][cy][cx+1]>co) {
				D[id][cy][cx+1]=co;
				Q.push({-co,id*1000000+cy*1000+cx+1});
			}
			if(D[1][cy][cx]>co+A[cy][cx]) {
				D[1][cy][cx]=co+A[cy][cx];
				Q.push({-D[1][cy][cx],1000000+cy*1000+cx});
			}
		}
		else {
			if(D[0][cy][cx]>co) {
				D[0][cy][cx]=co;
				Q.push({-D[0][cy][cx],cy*1000+cx});
			}
			if(D[1][cy+1][cx]>co+A[cy+1][cx]) {
				D[1][cy+1][cx]=co+A[cy+1][cx];
				Q.push({-D[1][cy+1][cx],1000000+cy*1000+1000+cx});
			}
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
