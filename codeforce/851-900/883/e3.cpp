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
ll N;

int ok[1000010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	set<ll> cand;
	for(k=2;k<=1000000;k++) {
		__int128 cur=k;
		__int128 sum=1+k;
		while(1) {
			cur*=k;
			sum+=cur;
			if(sum>1LL<<60) break;
			cand.insert(sum);
		}
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		if(cand.count(N)) {
			cout<<"YES"<<endl;
		}
		else if(N>=100) {
			ll LK=2,RK=1000000000;
			while(LK+1<RK) {
				ll M=(LK+RK)/2;
				if(1+M+M*M>=N) RK=M;
				else LK=M;
			}
			if(1+RK+RK*RK==N) {
				cout<<"YES"<<endl;
			}
			else {
				cout<<"NO"<<endl;
			}
				
		}
		else {
			cout<<"NO"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
