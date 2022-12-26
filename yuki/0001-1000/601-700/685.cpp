#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N;
ll mo=1000000007;

map<ll,ll> M[2],R[2];

ll hoge2(ll a,int lead) {
	if(a==0) return 0;
	if(R[lead].count(a)) return R[lead][a];
	ll ret=0;
	
	if(lead==1) {
		if(N&a) {
			// 11
			ret+=((N&(a-1))+1)%mo*(a%mo)%mo;
			// 10
			ret+=hoge2(a>>1,1);
			// 00,01
			ret+=2*hoge2(a>>1,0);
		}
		else {
			// 00,01
			ret+=2*hoge2(a>>1,1);
		}
	}
	else {
		// 11
		ret+=a%mo*(a%mo)%mo;
		// 10,01,00
		ret+=3*hoge2(a>>1,0);
	}
	
	//cout<<"R"<<lead<<" "<<a<<" "<<ret%mo<<endl;
	return R[lead][a]=ret%mo;
}


ll hoge1(ll a,int lead) {
	if(a==0) return 0;
	if(M[lead].count(a)) return M[lead][a];
	ll ret=0;
	
	if(lead==1) {
		if(N&a) {
			// 10
			ret+=hoge2(a>>1,1);
			// 00
			ret+=hoge1(a>>1,0);
		}
		else {
			// 00
			ret+=hoge1(a>>1,1);
		}
	}
	else {
		// 00
		ret+=hoge1(a>>1,0);
		// 10
		ret+=hoge2(a>>1,0);
	}
	//cout<<"M"<<lead<<" "<<a<<" "<<ret%mo<<endl;
	return M[lead][a]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cout<<hoge1(1LL<<60,1)<<endl;
	return;
	ll ret=0;
	for(i=1;i<=N;i++) {
		for(y=1;2*y<=i;y<<=1) if(i&y) ret+=y;
		cout<<ret<<endl;
	}
	cout<<ret<<endl;
	for(y=0;y<=N;y++) {
		int num=0;
		for(x=0;x<=y;x++) {
			if((x&y)<(x^y) && (x^y)<(x|y)) {
				//cout<<x<<" "<<y<<"   "<<(x&y)<<" "<<(x^y)<<" "<<(x|y)<<endl;
				num++;
			}
		}
		cout<<y<<" "<<num<<" "<<__builtin_popcount(y)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
