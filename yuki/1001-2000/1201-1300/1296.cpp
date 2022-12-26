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

int N,Q;
ll A[202020],B[202020];
set<int> cand;
ll mask[202020];

int hoge(ll v,int odd) {
	int num=0;
	int i;
	ll cur=0;
	
	FORR(s,cand) {
		if(s==0) {
			cur^=mask[s];
			continue;
		}
		if(v&mask[s]) {
			if(num%2) num++;
			cur^=mask[s];
		}
		else {
			if(num%2==0) num++;
		}
	}
	if(num%2!=odd) num++;
	
	if(cur!=v) num=1010;
	return num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,60) {
		for(x=N-1;x>=0;x--) if(A[x]&(1LL<<i)) {
			cand.insert(x);
			mask[x]|=1LL<<i;
			break;
		}
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>B[i];
		int ret=min(hoge(B[i],0),hoge(B[i]^((1LL<<60)-1),1));
		if(ret>1000) ret=-1;
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
