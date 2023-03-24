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

int N;
int H[202020];
int T[202020];
int R[202020];
int D[202020][20];
int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<int,int>> Vs;
	FOR(i,N) {
		cin>>H[i];
		Vs.push_back({H[i],i});
	}
	FOR(i,N) {
		cin>>T[i];
	}
	sort(ALL(Vs));
	int ma=0;
	FOR(i,N) R[Vs[i].second]=i;
	
	FOR(i,N) {
		x=Vs[i].second;
		ma=max(ma,T[x]);
		D[i][0]=lower_bound(ALL(Vs),make_pair(ma+1,0))-Vs.begin()-1;
		D[i][0]=max(D[i][0],0);
	}
	
	FOR(i,18) {
		FOR(j,N) D[j][i+1]=D[D[j][i]][i];
	}
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		x--,y--;
		if(H[y]<=T[x]) {
			cout<<1<<endl;
			continue;
		}
		x=lower_bound(ALL(Vs),make_pair(T[x]+1,0))-Vs.begin()-1;
		if(x<0) {
			cout<<-1<<endl;
			continue;
		}
		int ret=2;
		if(D[x][18]<R[y]) {
			cout<<-1<<endl;
		}
		else {
			for(i=17;i>=0;i--) {
				if(D[x][i]<R[y]) {
					ret+=1<<i;
					x=D[x][i];
				}
			}
			cout<<ret<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
