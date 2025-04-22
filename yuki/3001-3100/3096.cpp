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

int N,K;
const ll mo=998244353;
ll from[2020][5];
ll to[2020][5];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	from[0][0]=1;
	FOR(i,N-1) {
		ZERO(to);
		
		FOR(k,K+1) {
			FOR(x,5) FOR(y,5) {
				int add=0;
				if(y==1) add++;
				if(y>=3) add+=2;
				if(i%2==0&&y==0) add++;
				if(i%2==1&&y==2) add++;
				if(x==0&&y==4) continue;
				if(x==1&&y==3) continue;
				if(x==1&&y==4) continue;
				if(x==2&&y==3) continue;
				if(x==3&&y==0) continue;
				if(x==3&&y==1) continue;
				if(x==3&&y==4) continue;
				if(x==4&&y==1) continue;
				if(x==4&&y==2) continue;
				if(x==4&&y==3) continue;
				
				(to[k+add][y]+=from[k][x])%=mo;
			}
		}
		
		swap(from,to);
	}
	ll ret=0;
	FOR(i,K+1) ret+=from[i][0]+from[i][1]+from[i][2]+from[i][3+(N-1)%2];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
