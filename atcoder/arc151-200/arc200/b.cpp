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

int T;
int A[3];
ll ret[20][20][20][3];

ll p2[61],p5[30];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int a,b,c;
	
	p2[0]=p5[0]=1;
	FOR(i,60) p2[i+1]=p2[i]*2;
	FOR(i,25) p5[i+1]=p5[i]*5;
	
	int a2,a5,b2,b5;
	FOR(a2,55) FOR(a5,26) FOR(b2,55) FOR(b5,26) {
		ll a=1LL<<a2,b=1LL<<b2;
		ll c=1LL<<max(a2,b2);
		FOR(i,a5) {
			a*=5;
			if(a>=1LL<<60) a=0;
		}
		FOR(i,b5) {
			b*=5;
			if(b>=1LL<<60) b=0;
		}
		FOR(i,max(a5,b5)) {
			c*=5;
			if(c>=1LL<<60) c=0;
		}
		if(a==0||b==0||c==0) continue;
		int al=to_string(a).size();
		int bl=to_string(b).size();
		int cl=to_string(c).size();
		ret[al][bl][cl][0]=a;
		ret[al][bl][cl][1]=b;
		ret[al][bl][cl][2]=c;
		
		
	}
	
	cin>>T;
	while(T--) {
		cin>>a>>b>>c;
		if(ret[a][b][c][0]==0) {
			cout<<"No"<<endl;
		}
		else {
			cout<<"Yes"<<endl;
			cout<<ret[a][b][c][0]<<" "<<ret[a][b][c][1]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
