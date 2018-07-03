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
ll A[1010101];
ll S[1010101];
ll M[1010101];
int nex[1010101];
ll mul[1010101];
ll sum[1010101];
ll mo=1000000007;
ll p2[1010101];

ll F(int x,int y) {
	if(x==y) return max(0LL,A[x-1]);
	return max(0LL,F(x,y-1)+A[y-1]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	p2[0]=1;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
		p2[i+1]=p2[i]*2%mo;
	}
	
	map<ll,int> mp;
	mp[-1LL<<60]=N+1;
	ll ret=0;
	for(i=N-1;i>=0;i--) {
		if(A[i]>0) {
			auto it=mp.lower_bound(S[i]+1);
			it--;
			if(it!=mp.begin()) {
				nex[i]=it->second;
				ret+=sum[nex[i]]*p2[nex[i]-i-1];
				ret%=mo;
			}
		}
		else {
			auto it=mp.lower_bound(S[i+1]+1);
			it--;
			if(it==mp.begin()) {
				mul[i]=1;
				sum[i]=1;
			}
			else {
				nex[i]=it->second;
				mul[i]=mul[nex[i]]+1;
				sum[i]=sum[nex[i]]*p2[nex[i]-i]+p2[mul[i]-1];
				sum[i]%=mo;
				ret+=sum[nex[i]]*p2[nex[i]-i-1];
				ret%=mo;
			}
		}
		while(mp.rbegin()->first>=S[i+1]) mp.erase(mp.rbegin()->first);
		mp[S[i+1]]=i;
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
