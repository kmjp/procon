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

int N,D;

ll AX[4<<20];
ll BX[4<<20];
ll AY[4<<20];
ll BY[4<<20];
ll SX[4<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	FOR(i,N) {
		cin>>x>>y;
		x+=2<<20;
		y+=2<<20;
		AX[0]--;
		BX[0]+=x;
		AX[x]+=2;
		BX[x]-=2*x;
		AY[0]--;
		BY[0]+=y;
		AY[y]+=2;
		BY[y]-=2*y;
	}
	FOR(i,4<<20) {
		if(i) AX[i]+=AX[i-1],BX[i]+=BX[i-1];
		SX[i]=AX[i]*i+BX[i];
		
	}
	sort(SX,SX+(4<<20));
	
	ll ret=0;
	FOR(i,4<<20) {
		if(i) AY[i]+=AY[i-1],BY[i]+=BY[i-1];
		ll v=AY[i]*i+BY[i];
		if(v<=D) {
			x=lower_bound(SX,SX+(4<<20),D-v+1)-SX;
			ret+=x;
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
