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

int T;
ll N,X,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X>>K;
		int CD=0;
		while(1LL<<(CD+1)<=X) CD++;
		ll ret=0;
		if(K<=60) {
			__int128 L=X,R=X+1;
			L<<=K;
			R<<=K;
			R=min(R-1,(__int128)N);
			if(L<=R) ret+=R-L+1;
		}
		ll cur=X;
		while(K>0) {
			cur/=2;
			K--;
			if(cur==0) break;
			if(K==0) ret++;
			else {
				ll nex=X^1;
				if(K<=61) {
					__int128 L=nex,R=nex+1;
					L<<=(K-1);
					R<<=(K-1);
					R=min(R-1,(__int128)N);
					if(L<=R) ret+=R-L+1;
				}
			}
			X=cur;
		}
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
