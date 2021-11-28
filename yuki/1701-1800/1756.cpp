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

ll A,B;
ll N;
const ll mo=998244353;

ll ret=-1;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>N;
	if(A==0||A==B) {
		cout<<0<<endl;
		return;
	}
	for(i=1;i<=10000000;i++) if(ret==-1) {
		j=0;
		
		for(k=20;k>=0;k--) {
			int t=j+(1<<k);
			if(t>=i) continue;
			ll dx=B*(i-t);
			ll dy=A*(i+t);
			
			if(dx*B>=dy*A) j=t;
		}
		
		ll dx=B*(i-j);
		ll dy=A*(i+j);
		if(dx*B==dy*A) {
			dx=B*i;
			ret=8*((N-dx)%mo)%mo*((N-dy)%mo)%mo;
		}
		
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
