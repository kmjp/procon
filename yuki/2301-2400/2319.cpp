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

int N,M,X,Y,Q;
int P[202020];
vector<int> E[20200];
vector<int> B[20200];
map<int,int> num[20202];
const int DI=2000;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		P[i+1]=x;
	}
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for(i=1;i<=N;i++) {
		FORR(e,E[i]) {
			if(E[e].size()>=DI) {
				B[i].push_back(e);
				num[P[i]][e]++;
			}
		}
	}
	cin>>Q;
	while(Q--) {
		cin>>X>>Y;
		if(P[X]==P[Y]) {
			cout<<"No"<<endl;
			continue;
		}
		int ok=0;
		if(E[X].size()>=DI) {
			if(num[P[Y]][X]>0) ok=1;
		}
		else {
			FORR(e,E[X]) if(P[e]==P[Y]) ok=1;
		}
		
		if(ok==0) {
			cout<<"No"<<endl;
		}
		else {
			cout<<"Yes"<<endl;
			FORR(e,B[X]) num[P[X]][e]--;
			P[X]=P[Y];
			FORR(e,B[X]) num[P[X]][e]++;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
