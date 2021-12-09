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


string T;
int N,K;
const ll mo=998244353;


ll from[5050][2];
ll to[5050][2];
int status[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T>>K;
	N=T.size();
	K=min(K,N);
	
	FOR(i,N+1) status[i]=-5;
	
	FOR(x,N) {
		FOR(i,N) {
			if(i+3<=N) {
				string C=T.substr(i,3);
				if(C=="ARC") status[i]=0,status[i+1]=status[i+2]=-4;
				if(C=="AR*") status[i]=2,status[i+1]=-4;
				if(C=="A**") status[i]=1;
				if(C=="**C") status[i+2]=-1;
				if(C=="*RC") status[i+1]=-2,status[i+2]=-4;
				if(C=="*R*") status[i+1]=3;
			}
			if(status[i]>=-4) T[i]='*';
		}
	}
	
	from[0][0]=1;
	int pre=-5;
	FOR(i,N) {
		if(status[i]==-4) continue;
		ZERO(to);
		FOR(j,i+2) {
			// not cover
			(to[j][0]+=from[j][0])%=mo;
			if(status[i]==-5) continue;
			
			// cover
			if(status[i]==0) {
				(to[j+1][1]+=27*from[j][0])%=mo;
				(to[j+1][0]+=26*from[j][0])%=mo;
				if(pre==3||pre==1||pre==2) {
					(to[j+1][1]+=27*from[j][1])%=mo;
					(to[j+1][0]+=27*from[j][1])%=mo;
				}
			}
			else if(status[i]==3) {
				(to[j+1][1]+=2*from[j][1])%=mo;
			}
			else if(status[i]>0) {
				int mul=(status[i]==1)?3:9;
				(to[j+1][1]+=(mul-1)*from[j][0])%=mo;
				if(pre==3||pre==1||pre==2) {
					(to[j+1][1]+=mul*from[j][1])%=mo;
				}
				
			}
			else {
				int mul=(status[i]==-1)?3:9;
				(to[j+1][0]+=(mul-1)*from[j][1])%=mo;
				(to[j+1][1]+=mul*from[j][1])%=mo;
			}
		}
		swap(from,to);
		pre=status[i];
	}
	
	ll ret=0;
	for(i=0;i<=K;i++) ret+=from[i][0];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
