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
vector<int> E[201010],EB[202020];
int ID[202020];

int C[202020];
int BC[751];
int BCH[202020][751];

int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	MINUS(ID);
	int cur=0;
	FOR(i,N) if(E[i].size()>700) ID[i]=cur++;
	FOR(i,N) FORR(e,E[i]) if(ID[e]>=0) EB[i].push_back(ID[e]);
	
	
	cin>>Q;
	while(Q--) {
		cin>>i>>x;
		x--;
		if(i==1) {
			if(ID[x]==-1) {
				FORR(e,E[x]) C[e]++;
			}
			else {
				BC[ID[x]]++;
			}
		}
		else {
			int ret=C[x];
			C[x]=0;
			FORR(e,EB[x]) {
				ret+=BC[e]-BCH[x][e];
				BCH[x][e]=BC[e];
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
