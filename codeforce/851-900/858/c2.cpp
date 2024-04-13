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

int T,N;
int P[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<vector<int>> C;
	for(P[0]=-3;P[0]<=3;P[0]++) for(P[1]=P[0];P[1]<=3;P[1]++) for(P[2]=P[1];P[2]<=3;P[2]++) for(P[3]=P[2];P[3]<=3;P[3]++) {
		if(P[0]+P[1]!=P[2]*P[3]) continue;
		if(P[0]+P[2]!=P[1]*P[3]) continue;
		if(P[0]+P[3]!=P[1]*P[2]) continue;
		if(P[1]+P[2]!=P[0]*P[3]) continue;
		if(P[1]+P[3]!=P[0]*P[2]) continue;
		if(P[2]+P[3]!=P[0]*P[1]) continue;
		C.push_back({P[0],P[1],P[2],P[3]});
	}
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		int tar=N;
		ll ret=1LL<<60;
		FOR(i,2*N) cin>>P[i];
		sort(P,P+2*N);
		if(N==1) {
			ret=min(ret,abs((ll)P[0]-P[1]));
		}
		if(N==2) {
			ret=min(ret,abs((ll)P[0]-2)+abs((ll)P[1]-2)+abs((ll)P[2]-2)+abs((ll)P[3]-2));
		}
		if(N%2==0) {
			ll sum=0;
			FOR(i,2*N) {
				if(i!=2*N-1) sum+=abs(P[i]+1);
				else sum+=abs(P[i]-N);
			}
			ret=min(ret,sum);
		}
		ll sum=0;
		FOR(i,2*N) sum+=abs(P[i]);
		ret=min(ret,sum);
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
