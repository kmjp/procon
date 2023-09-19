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
string K;
ll p10[20];

ll hoge(ll N,ll v) {
	ll ret=0;
	int i;
	FOR(i,19) {
		if(N/p10[i]<v) break;
		if((v+1)*p10[i]>N) {
			ret+=N-v*p10[i]+1;
		}
		else {
			ret+=p10[i];
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,18) p10[i+1]=p10[i]*10;
	
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		
		ll ret=0;
		FOR(i,K.size()) {
			ret++;
			FOR(j,K[i]-'0') {
				ll a=atoll(K.substr(0,i).c_str())*10+j;
				if(a>0) ret+=hoge(N,a);
			}
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
