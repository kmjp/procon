#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S;
int N,K;

const ll mo=998244353;


ll from[303][306];
ll to[303][306];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>K;
	vector<int> V;
	V.push_back(0);
	
	int sum=0;
	FORR(c,S) {
		if(c=='1') V.back()++, sum++;
		else V.push_back(0);
	}
	K=min(K,sum);
	N=V.size();
	
	from[K][0]=1;
	FOR(y,V.size()) {
		int v=V[y];
		ZERO(to);
		for(j=K;j>=0;j--) {
			for(i=0;i<=sum;i++) if(from[j][i]) {
				for(int tar=0;tar<=min(v+j,sum);tar++) {
					if(y==V.size()-1 && tar>v) break;
					if(tar<=v) {
						if(i+(tar-v)>=0) (to[j][i+(tar-v)]+=from[j][i])%=mo;
					}
					else {
						(to[j-(tar-v)][i+(tar-v)]+=from[j][i])%=mo;
					}
				}
			}
		}
		swap(from,to);
	}
	
	ll ret=0;
	FOR(i,K+1) ret+=from[i][0];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
