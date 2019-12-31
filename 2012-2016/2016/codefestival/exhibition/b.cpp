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

int N;
ll A[202020];
ll p10[20];

int ok(int d,int c) {
	ll mo=p10[d+1];
	vector<pair<ll,ll>> V;
	V.push_back({c*p10[d],(c+1)*p10[d]-1});
	
	int i;
	FOR(i,N) {
		vector<pair<ll,ll>> V2=V;
		FORR(v,V) {
			ll a=((v.first-A[i])%mo+mo)%mo;
			ll b=((v.second-A[i])%mo+mo)%mo;
			if(a>b || a==0) return 1;
			V2.push_back({a,b});
		}
		sort(ALL(V2));
		V.clear();
		FORR(v,V2) {
			if(V.size() && v.first<=V.back().second+1) {
				V.back().second=max(V.back().second,v.second);
			}
			else {
				V.push_back(v);
			}
		}
	}
	
	return 0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	p10[0]=1;
	FOR(i,18) p10[i+1]=p10[i]*10;
	
	int ret=0;
	for(int d=0;d<=17;d++) {
		for(x=9;x>=0;x--) {
			if(ok(d,x)) {
				ret+=x;
				break;
			}
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
