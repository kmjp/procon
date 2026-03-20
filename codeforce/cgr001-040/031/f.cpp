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

int T,H,W;
int dp_up[5050][5050];   //上か
int dp_lef1[5050][5050]; //左から、ただし左下のバーを使い落ちないようにした
int dp_lef2[5050][5050]; //左から、ただし右下のバーを使い落ちないようにした
const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	ll r2=modpow(2);
	ll r3=modpow(3);
	ll r4=modpow(4);
	
	//1手目だけは固定
	dp_up[0][0]=1;
	dp_up[1][0]=9*r4%mo*r4%mo;
	dp_lef1[0][1]=1*r4%mo*3%mo*r4%mo*3*r4%mo; //左下で蓋をし、右上も右下も邪魔をしない
	dp_lef2[0][1]=3*r4%mo*1%mo*r4%mo*3*r4%mo; //左下で蓋をしなかったが、右下が蓋をした。右上は邪魔しない
	
	FOR(y,5010) FOR(x,5010) if(x+y) {
		//上から落ちてきて、さらに下
		(dp_up[y+1][x]+=1LL*dp_up[y][x]*9%mo*r4%mo*r4%mo)%=mo;  // 左下も右下も邪魔しない
		//上から落ちてきて右
		(dp_lef1[y][x+1]+=1LL*dp_up[y][x]*1*r4%mo*2*r3%mo*3*r4%mo)%=mo; //左下で蓋をし、右上も右下も邪魔をしない
		(dp_lef2[y][x+1]+=1LL*dp_up[y][x]*3*r4%mo*2*r3%mo*r4%mo)%=mo;   //左下で蓋をせず、右下が下をふさいだ。右上は邪魔をしない
		
		//左からきて下
		(dp_up[y+1][x]+=1LL*dp_lef1[y][x]*2*r3%mo*3*r4%mo)%=mo;
		//左からきて右
		(dp_lef1[y][x+1]+=1LL*dp_lef1[y][x]*r3%mo*(3*r4)%mo*(3*r4)%mo)%=mo;
		(dp_lef2[y][x+1]+=1LL*dp_lef1[y][x]*2*r3%mo*(r4)%mo*(3*r4)%mo)%=mo;
		
		//左からきて下
		(dp_up[y+1][x]+=1LL*dp_lef2[y][x]*3*r4%mo)%=mo;
		//左からきて右
		(dp_lef2[y][x+1]+=1LL*dp_lef2[y][x]*r4%mo*(3*r4)%mo)%=mo;
	}
	
	
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		ll ret=0;
		FOR(x,W) ret+=dp_up[H][x];
		FOR(y,H) ret+=dp_lef1[y][W]+dp_lef2[y][W];
		ret=(mo+1-ret%mo)*modpow(4,(H+1)*(W+1));
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
