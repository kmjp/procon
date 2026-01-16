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

int N,M,X;
const ll mo=998244353;
map<pair<int,int>,ll> F,T;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>X;
	
	ll ret=0;
	FOR(i,M+1) {
		int step=N-2;
		int a=X,b=i;
		while(step) {
			if(a==b&&step>=3) {
				step%=3;
			}
			else if(b&&a>=2*b&&step>=3) {
				int c=min(a/b/2,step/3);
				a-=2*c*b;
				step-=3*c;
			}
			else {
				a=abs(b-a);
				swap(a,b);
				step--;
			}
		}
		(ret+=1LL*a*b)%=mo;
	}
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
