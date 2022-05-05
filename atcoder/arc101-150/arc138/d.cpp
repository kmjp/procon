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

int N,K;
int A[1<<18];
int vis[1<<18];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	if(N==1) {
		cout<<"Yes"<<endl;
		cout<<"0 1"<<endl;
		return;
	}
	
	if(K%2==0||K==N) {
		cout<<"No"<<endl;
		return;
	}
	
	vector<int> T,cand;
	FOR(i,1<<N) if(__builtin_popcount(i)==K) {
		x=i;
		FORR(t,T) x=min(x,t^x);
		if(x) T.push_back(x), cand.push_back(i);
	}
	
	cout<<"Yes"<<endl;
	FOR(i,1<<N) {
		x=i^(i>>1);
		y=0;
		FOR(j,N) if(x&(1<<j)) y^=cand[j];
		cout<<y<<" ";
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
