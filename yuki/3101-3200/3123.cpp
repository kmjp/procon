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
ll mo;
int N;
ll p2[5<<20];
ll fact[5<<20];
ll fact2[5<<20];
ll dp2[5<<20];
ll dp3[5<<20];
ll dp4[5<<20];
ll dp5[5<<20];
ll dp6[5<<20];
ll dp7[5<<20];
ll ret[5<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T>>mo;
	
	p2[0]=fact[0]=fact2[0]=fact2[1]=1%mo;
	dp5[1]=1;
	dp5[2]=2;
	for(i=1;i<(5<<20);i++) {
		p2[i]=p2[i-1]*2%mo;
		fact[i]=fact[i-1]*i%mo;
		ret[i]=fact[i];
		if(i==1) continue;
		
		fact2[i]=fact2[i-2]*i%mo;
		
		// 90“x‰ñ“]‘ÎÌ
		if(i%4==0||i%4==1) dp2[i]=p2[i/4]*fact2[(i-2)/2]%mo;
		
		
		if(i<=3) dp3[i]=2%mo;
		else if(i<=5) dp3[i]=6%mo;
		else if(i%2==0) dp3[i]=(2*dp3[i-2]+(i-2)*dp3[i-4])%mo;
		else dp3[i]=(2*dp3[i-2]+(i-3)*dp3[i-4])%mo;
		
		if(i%2==0) dp4[i]=(fact2[i]-dp3[i]-dp2[i])%mo;
		else dp4[i]=(fact2[i-1]-dp3[i]-dp2[i])%mo;
		
		if(i>=3) dp5[i]=(dp5[i-1]+(i-1)*dp5[i-2])%mo;
		
		
		ll c5=dp5[i]-dp3[i];
		dp7[i]=fact[i]-(dp2[i]+dp3[i]+dp4[i]+c5+c5);
		
		
		ret[i]=(dp7[i]*8+dp2[i]*2+dp3[i]*2+dp4[i]*4+c5*4+c5*4)%mo;
		ret[i]=(ret[i]+mo)%mo;
	}
	
	
	
	
	while(T--) {
		cin>>N;
		cout<<ret[N]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
