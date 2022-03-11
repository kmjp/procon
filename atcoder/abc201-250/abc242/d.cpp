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

string S;
int Q;
ll T,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>Q;
	FOR(i,Q) {
		cin>>T>>K;
		K--;
		int ok=-1;
		FOR(j,3) {
			ll cur=T;
			ll pos=K;
			int now=j;
			while(cur&&pos) {
				if(pos%2==1) {
					now=(now+1)%3;
				}
				else {
					now=(now+2)%3;
				}
				cur--;
				pos/=2;
			}
			now=(now+(cur%3)*2)%3;
			if(now==S[pos]-'A') s='A'+j;
		}
		cout<<s<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
