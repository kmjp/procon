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


int N,X;
int L[505];

ll from[505][505];
ll to[505][505];
const ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) cin>>L[i];
	sort(L,L+N);
	reverse(L,L+N);
	from[0][0]=1;
	FOR(i,N) {
		ZERO(to);
		for(x=0;x<=N/2+2;x++) {
			FOR(y,X+1) if(from[x][y]) {
				// add
				if(y+L[i]<=X) (to[x+1][y+L[i]]+=from[x][y])%=mo;
				//keep
				if(x) (to[x][y]+=from[x][y]*(y-(L[i]-1)*x))%=mo;
				
				for(j=1;j<=L[i]&&y+j<=X;j++) {
					// conn1
					if(x) (to[x][y+j]+=from[x][y]*2*x)%=mo;
					// conn2
					if(x>=2) (to[x-1][y+j]+=from[x][y]*x*(x-1)*(L[i]-j+1))%=mo;
				}
			}
		}
		swap(from,to);
	}
	
	cout<<from[1][X]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
