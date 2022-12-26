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

int N;
int C[1010101];
map<int,int> num[1010101];

int ma[1010101];
const ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) C[i]=i;
	for(i=1;i<=N;i++) if(C[i]>1) {
		x=C[i];
		for(j=x;j<=N;j+=x) {
			while(C[j]%x==0) {
				C[j]/=x;
				num[j][x]++;
			}
		}
	}
	
	for(i=1;i<=N-1;i++) {
		x=N-i;
		if(x<i) break;
		FORR2(a,b,num[i]) ma[a]=max(ma[a],b+num[x][a]);
		FORR2(a,b,num[x]) ma[a]=max(ma[a],b+num[i][a]);
	}
	
	ll ret=1;
	for(i=1;i<=N;i++) {
		FOR(j,ma[i]) ret=ret*i%mo;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
