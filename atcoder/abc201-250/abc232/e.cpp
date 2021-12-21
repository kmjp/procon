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


int H,W;
int K;
int X1,Y1,X2,Y2;
ll from[2][2];
ll to[2][2];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	cin>>X1>>Y1>>X2>>Y2;
	
	from[X1==X2][Y1==Y2]=1;
	
	
	FOR(i,K) {
		ZERO(to);
		(to[1][0]+=from[0][0])%=mo;
		(to[0][1]+=from[0][0])%=mo;
		(to[0][0]+=(H+W-4)*from[0][0])%=mo;
		
		(to[1][1]+=from[0][1])%=mo;
		(to[0][1]+=(H-2)*from[0][1])%=mo;
		(to[0][0]+=(W-1)*from[0][1])%=mo;
		
		(to[1][1]+=from[1][0])%=mo;
		(to[1][0]+=(W-2)*from[1][0])%=mo;
		(to[0][0]+=(H-1)*from[1][0])%=mo;
		
		(to[0][1]+=(H-1)*from[1][1])%=mo;
		(to[1][0]+=(W-1)*from[1][1])%=mo;
		
		swap(from,to);
	}
	cout<<from[1][1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
