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

int T,N,Q;
ll A[202020];
ll ret[35];
int num[35];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		ZERO(num);
		FOR(i,N) {
			cin>>A[i];
			FOR(j,35) if(A[i]&(1LL<<j)) num[j]++;
		}
		int sum=0;
		FOR(i,35) if(num[i]) sum++;
		FOR(i,35) {
			if(i<=sum) ret[i]=0;
			else ret[i]=1LL<<30;
		}
		ll tot=0;
		FOR(i,35) if(num[i]==0) {
			sum++;
			for(j=i;j>=0;j--) if(num[j]==0) {
				x=0;
				ll dif=1LL<<35;
				FOR(k,N) {
					ll d=(1LL<<j)-(A[k]&((1LL<<j)-1));
					if(d<dif) {
						dif=d;
						x=k;
					}
				}
				tot+=dif;
				num[j]++;
				A[x]|=1LL<<j;
				FOR(k,j) if(A[x]&(1LL<<k)) {
					A[x]^=1LL<<k;
					num[k]--;
				}
			}
			ret[sum]=tot;
		}
		
		while(Q--) {
			cin>>x;
			int ma=0;
			FOR(i,35) if(ret[i]<=x) ma=i;
			cout<<ma<<endl;
		}
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
