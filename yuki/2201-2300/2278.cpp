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

int N,K,T;
string S;

int win(int cur,int left) {
	int turn=S[cur]-'A';
	
	int L,R;
	for(L=cur;L>=0;L--) if(S[L]!=S[cur]) break;
	for(R=cur;R<N;R++) if(S[R]!=S[cur]) break;
	
	int ret=turn^1;
	if(L+1==R-1) {
		ret=turn^1;
		if(left%2) {
			if(cur>0&&win(cur-1,left-1)==turn) ret=turn;
			if(cur<N-1&&win(cur+1,left-1)==turn) ret=turn;
		}
	}
	else {
		if(L>=0&&left>=cur-L&&(cur-L)%2==left%2) ret=turn;
		if(R<N&&left>=R-cur&&(R-cur)%2==left%2) ret=turn;
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>T>>S;
	if(win(K-1,T)==0) {
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
