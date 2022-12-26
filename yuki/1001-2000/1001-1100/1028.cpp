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
vector<pair<int,int>> C[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		FOR(x,N) {
			cin>>r;
			C[r-1].push_back({y,x});
		}
	}
	int ret=0;
	FOR(i,N) {
		int U[1010]={};
		int D[1010]={};
		int R[1010]={};
		int base=0;
		FORR(v,C[i]) {
			y=v.first;
			x=v.second;
			base+=x;
			if(y>x) U[y-x-1]++;
			if(y+x<N) D[y+x+1]++;
		}
		int add=0;
		int sum=0;
		FOR(y,N) {
			add+=D[y];
			sum+=add;
			R[y]+=sum+base;
		}
		add=sum=0;
		int mi=1010101;
		for(y=N-1;y>=0;y--) {
			add+=U[y];
			sum+=add;
			R[y]+=sum;
			mi=min(mi,R[y]);
		}
		ret+=mi;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
