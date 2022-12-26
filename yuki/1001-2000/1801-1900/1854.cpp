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

int T,N,P[505];
vector<int> ret;

void go(int x) {
	assert(P[x]!=x&&P[x+1]!=x+1);
	swap(P[x],P[x+1]);
	ret.push_back(x);
}

void hoge(int L,int R) {
	if(R<L) return;
	
	int cur=0;
	int i,j;
	for(i=L;i<=R;i++) {
		if(P[i]==i) {
			hoge(L,i-1);
			hoge(i+1,R);
			return;
		}
		if(P[i]<L||P[i]>R) {
			ret.push_back(-1);
			return;
		}
		if(P[i]==R) cur=i;
	}
	
	if(L+1==R) {
		go(L);
		return;
	}
	
	for(i=cur+1;i<=R;i++) {
		if(P[i]!=i-1) {
			for(j=i-1;j>cur;j--) go(j);
			go(cur);
			for(j=cur+1;j<i;j++) go(j);
			cur=i;
		}
	}
	while(cur<R) go(cur++);
	hoge(L,R-1);
	
	
		
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>P[i+1];
		ret.clear();
		hoge(1,N);
		
		if(count(ALL(ret),-1)) {
			cout<<-1<<endl;
		}
		else {
			FOR(i,N) assert(P[i+1]==i+1);
			cout<<ret.size()<<endl;
			FORR(r,ret) cout<<r<<" ";
			cout<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
