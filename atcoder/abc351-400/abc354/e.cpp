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
vector<pair<int,int>> cand;
int A[18],B[18];

int win[1<<18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		FOR(j,i) if(A[i]==A[j]||B[i]==B[j]) cand.push_back({j,i});
	}
	
	int mask;
	FOR(mask,1<<N) {
		FORR2(a,b,cand) if((mask&(1<<a))&&(mask&(1<<b))&&win[mask^(1<<a)^(1<<b)]==0) win[mask]=1;
	}
	if(win[(1<<N)-1]) {
		cout<<"Takahashi"<<endl;
	}
	else {
		cout<<"Aoki"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
