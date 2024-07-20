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
ll S,K;

ll hoge(ll v) {
	if(v<0||v>K) return -1;
	ll ret=0;
	ll CS=S;
	ll get=K-v;
	while(v&&(CS%10!=0&&CS%10!=2)) {
		v--;
		CS+=CS%10;
	}
	if(CS%10==2) {
		CS+=20*(v/4);
	}
	v%=4;
	while(v) {
		v--;
		CS+=CS%10;
	}
	return get*CS;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S>>K;
		
		ll ma=hoge(0);
		FOR(i,4) {
			int L=0,R=(K-i)/4;
			while(R-L>=100) {
				int M1=(2*L+R)/3;
				int M2=(2*R+L)/3;
				ll v1=hoge(M1*4+i);
				ll v2=hoge(M2*4+i);
				ma=max({ma,v1,v2});
				if(v1>=v2) R=M2;
				if(v1<=v2) L=M1;
			}
			for(j=L-10;j<=R+10;j++) {
				ma=max(ma,hoge(j*4+i));
			}
		}
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
