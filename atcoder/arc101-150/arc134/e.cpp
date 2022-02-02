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

int N,A[202];
const ll mo=998244353;

ll from[1<<21];
ll to[1<<21];
int table[202];
int win[1<<16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	win[0]=1;
	for(int mask=1;mask<1<<16;mask++) {
		int ma=0;
		FOR(i,16) if(mask&(1<<i)) ma=(i+1)*12;
		for(x=1;x<=ma;x++) {
			int mask2=0;
			set<int> S;
			FOR(i,16) if(mask&(1<<i)) {
				y=(i+1)*12%x;
				if(y%12) {
					S.insert(y);
				}
				else {
					if(y) mask2|=(1<<(y/12-1));
				}
			}
			if(S.size()) {
				if(mask2) continue;
				if(S.size()==1&&*S.begin()==1) win[mask]=1;
				if(S.size()==1&&*S.begin()==2) win[mask]=1;
				if(S.size()==2&&*S.begin()==4&&*S.rbegin()==8) win[mask]=1;
			}
			else {
				if(win[mask2]==0) win[mask]=1;
			}
		}
	}
	
	
	FOR(i,201) table[i]=20;
	FOR(i,16) table[(i+1)*12]=i;
	table[1]=16;
	table[2]=17;
	table[4]=18;
	table[8]=19;
	
	int mask;
	cin>>N;
	from[0]=1;
	FOR(i,N) {
		cin>>x;
		
		ZERO(to);
		int C[21]={};
		for(j=1;j<=x;j++) C[table[j]]++;
		
		FOR(mask,1<<21) if(from[mask]) FOR(j,21) to[mask|(1<<j)]+=from[mask]*C[j];
		ZERO(from);
		FOR(mask,1<<21) {
			x=((mask&65535)>0)+((mask&(1<<16))>0)+((mask&(1<<17))>0)+((mask&(3<<18))>0)+((mask&(1<<20))>0)*2;
			if(x>1) {
				(from[1<<20]+=to[mask])%=mo;
			}
			else {
				(from[mask]+=to[mask])%=mo;
			}
		}
	}
	
	
	ll ret=0;
	FOR(mask,1<<21) ret+=from[mask];
	FOR(mask,1<<16) if(win[mask]==0) ret+=mo-from[mask];
	ret+=mo-from[1<<16];
	ret+=mo-from[1<<17];
	ret+=mo-from[3<<18];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
