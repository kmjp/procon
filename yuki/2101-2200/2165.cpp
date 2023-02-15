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
int A[101010];
set<int> S[31];
int nim;

void update(int i,int d) {
	int x;
	FOR(x,30) S[x].erase(i);

	nim^=A[i];
	A[i]-=d;
	nim^=A[i];
	FOR(x,30) if(A[i]&(1<<x)) S[x].insert(i);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		nim^=A[i];
		FOR(x,30) if(A[i]&(1<<x)) S[x].insert(i);
	}
	
	if(nim==0) {
		cout<<0<<endl;
		cin>>x>>y;
		update(x-1,y);
		cin>>x;
		if(x==-1) return;
	}
	else {
		cout<<1<<endl;
	}
	
	while(1) {
		x=0;
		while(2<<x<=nim) x++;
		y=*S[x].begin();
		k=A[y]-(nim^A[y]);
		update(y,k);
		assert(nim==0);
		cout<<y+1<<" "<<k<<endl;
		cin>>x;
		if(x==-1) return;
		cin>>x>>y;
		update(x-1,y);
		cin>>x;
		if(x==-1) return;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
