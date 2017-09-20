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
vector<double> V[101010];

void hoge(int a) {
	if(V[a].size()) return;
	if(a==1) {
		V[a].push_back(1);
		return;
	}
	int i;
	V[a].resize(a,a);
	if(a%2==0) {
		hoge(a/2);
		FOR(i,a/2) V[a][i]+=V[a/2][i],V[a][i+a/2]+=V[a/2][i];
	}
	else {
		hoge(a/2);
		hoge(a/2+1);
		FOR(i,a) {
			if(i<a/2) V[a][i]+=V[a/2][i]*0.5;
			else V[a][i]+=V[a/2+1][i-(a/2)]*0.5;
			
			if(i<a/2+1) V[a][i]+=V[a/2+1][i]*0.5;
			else V[a][i]+=V[a/2][i-(a/2+1)]*0.5;
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	hoge(N);
	FOR(i,N) _P("%.12lf%c",V[N][i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
