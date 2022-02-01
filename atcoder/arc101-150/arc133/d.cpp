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

ll L,R,V;
const ll mo=998244353;

ll memo[66][2][2][2];
ll A,B;
int va,vb;
int beless;
__int128 hoge(int ta,int tb,int le,int d) {
	if(d==1) {
		return beless==0||le==1;
	}
	ll& ret=memo[d][ta][tb][le];
	if(ret>=0) return ret;
	ret=0;
	int x,y;
	FOR(x,2) FOR(y,2) {
		int v=(x&va)^(y&vb);
		if((V>>d)%2!=v) continue;
		if(le==0&&x>y) continue;
		if(ta==0&&x==0&&(A>>d)%2==1) continue;
		if(tb==0&&y==1&&(B>>d)%2==0) continue;
		ret+=hoge(ta||(x==1&&(A>>d)%2==0),tb||(y==0&&(B>>d)%2==1),le||x<y,d-1);
	}
	ret%=mo;
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>L>>R>>V;
	R++;
	ll ret=0;
	ll m[4]={0,0,1,3};
	int valid[4]={0,1,0,1};
	FOR(x,4) FOR(y,4) if((m[x]^m[y])==V%4) {
		A=L,B=R;
		while((A+0)%4!=x) A++;
		while((B+4)%4!=y) B--;
		if(A>=B) continue;
		va=valid[x];
		vb=valid[y];
		beless=x>=y;
		
		MINUS(memo);
		ret+=hoge(0,0,0,60);
		
	}
	
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
