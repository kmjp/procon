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

int N,M;
int R[1010];
int C[1010];
vector<int> RS,CS;

int cand[1010][1010];

void hoge(int y,int x,int h,int w) {
	if(h<=0 || w<=0) return;
	if(h<=w) {
		if(1<<min(20,h)<w) {
			_P("-1\n");
			exit(0);
		}
		for(int i=x;i<x+w;i++) cand[y][i]=(i-x)>=(w/2);
		hoge(y+1,x,h-1,w/2);
		hoge(y+1,x+w/2,h-1,w-w/2);
	}
	else {
		if(1<<min(20,w)<h) {
			_P("-1\n");
			exit(0);
		}
		for(int i=y;i<y+h;i++) cand[i][x]=(i-y)>=(h/2);
		hoge(y,x+1,h/2,w-1);
		hoge(y+h/2,x+1,h-h/2,w-1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>R[i];
		RS.push_back(R[i]);
	}
	FOR(i,M) {
		cin>>C[i];
		CS.push_back(C[i]);
	}
	sort(ALL(RS));
	sort(ALL(CS));
	RS.erase(unique(ALL(RS)),RS.end());
	CS.erase(unique(ALL(CS)),CS.end());
	FOR(i,N) R[i]=lower_bound(ALL(RS),R[i])-RS.begin();
	FOR(i,M) C[i]=lower_bound(ALL(CS),C[i])-CS.begin();
	
	hoge(0,0,RS.size(),CS.size());
	
	FOR(y,N) {
		string S=string(M,'0');
		FOR(x,M) S[x]+=cand[R[y]][C[x]];
		cout<<S<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
