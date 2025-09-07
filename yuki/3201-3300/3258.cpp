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
ll F[202020];
vector<int> pos[202020];

int num(int v,int L,int R) {
	// F{L]...F[R-1]‚É‚¨‚¯‚év‚Ì”
	return lower_bound(ALL(pos[v]),R)-lower_bound(ALL(pos[v]),L);
}

int dfs(int L,int R) {
	//íœ‚Å‚«‚é‰ñ”
	for(int TL=L,TR=R-1;TL<=TR;TL++,TR--) {
		if(num(F[TL],L,R)==1) {
			return dfs(L,TL)+dfs(TL+1,R);
		}
		if(num(F[TR],L,R)==1) {
			return dfs(L,TR)+dfs(TR+1,R);
		}
		
	}
	return R-L;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> Fs;
	
	FOR(i,N) {
		cin>>F[i];
		Fs.push_back(F[i]);
	}
	sort(ALL(Fs));
	FOR(i,N) {
		F[i]=lower_bound(ALL(Fs),F[i])-Fs.begin();
		pos[F[i]].push_back(i);
	}
	
	int num=N-dfs(0,N);
	if(num%2) {
		cout<<"Alice"<<endl;
	}
	else {
		cout<<"Bob"<<endl;
	}
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
