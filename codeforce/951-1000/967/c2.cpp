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


int T,N;
int D[1010],P[1010];
set<int> S,F;

int ask(int a,int b) {
	cout<<"? "<<a<<" "<<b<<endl;
	cin>>a;
	return a;
}

void dfs(int a,int b) {
	if(F.count(b)) return;
	if(a==b) return;
	
	int x=ask(a,b);
	
	if(a==x||b==x) {
		P[b]=a;
		D[b]=D[a]+1;
		S.erase(b);
		F.insert(b);
	}
	else {
		dfs(a,x);
		dfs(x,b);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		S.clear();
		F.clear();
		F.insert(1);
		FOR(i,N) if(i) S.insert(i+1);
		while(S.size()) {
			x=*S.begin();
			dfs(1,x);
		}
		cout<<"!";
		for(i=2;i<=N;i++) cout<<" "<<i<<" "<<P[i];
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
