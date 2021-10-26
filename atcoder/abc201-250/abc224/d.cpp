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

int M;
int E[9][9];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1][y-1]=E[y-1][x-1]=1;
	}
	vector<int> P;
	FOR(i,8) {
		cin>>y;
		P.push_back(y-1);
	}
	map<vector<int>,int> D;
	D[P]=0;
	queue<vector<int>> Q;
	Q.push(P);
	while(Q.size()) {
		auto p=Q.front();
		Q.pop();
		int cur=D[p];
		int i;
		FOR(i,8) if(p[i]!=i) break;
		if(i==8) {
			cout<<D[p]<<endl;
			return;
		}
		int mask=(1<<9)-1;
		FOR(i,8) mask ^= 1<<p[i];
		FOR(i,9) if(mask&(1<<i)) x=i;
		FOR(i,8) if(E[p[i]][x]) {
			y=p[i];
			p[i]=x;
			if(D.count(p)==0) {
				D[p]=cur+1;
				Q.push(p);
			}
			p[i]=y;
		}
		
	}
	
	cout<<-1<<endl;
	
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
