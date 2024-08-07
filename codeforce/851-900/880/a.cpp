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
ll A,B,C,K;

ll L[7]={0,1,10,100,1000,10000,100000};
ll R[7]={0,9,99,999,9999,99999,999999};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C>>K;
		
		for(x=L[A];x<=R[A];x++) {
			ll ba=max(L[B],L[C]-x);
			ll bb=min(R[B],R[C]-x);
			if(ba>bb) continue;
			if(bb-ba+1<K) {
				K-=bb-ba+1;
				continue;
			}
			else {
				ll b=ba+K-1;
				K=0;
				cout<<x<<" + "<<b<<" = "<<x+b<<endl;
				break;
			}
		}
		if(K>0) cout<<-1<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
