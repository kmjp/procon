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

struct RollingHash {
	static const ll mo0=1000000021,mo1=1000000009;
	static ll mul0,mul1;
	static const ll add0=1000010007, add1=1003333331;
	static vector<ll> pmo[2];
	string s; int l; vector<ll> hash_[2];
	void init(string s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0)>>5)%259,mul1=10007+(((ll)&mul1)>>5)%257;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
	}
	/*ˆÈ‰ºll”Å*/
	ll hash(int l,int r) { // s[l..r]
		if(l>r) return 0;
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return (((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0)<<32) | 
			             ((hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;

int N;
string S,T;
RollingHash rh[2];

int hoge(int L,int R) {
	int i;
	int A=0;
	for(i=20;i>=0;i--) {
		if(L-(A+(1<<i))<0) continue;
		if(R+(A+(1<<i))>=N) continue;
		
		auto h1=rh[0].hash(L-(A+(1<<i)),L);
		auto h2=rh[1].hash(N-1-(R+(A+(1<<i))),N-1-R);
		if(h1==h2) A+=1<<i;
	}
	
	L-=A+1;
	R+=A+1;
	int B=-1,C=-1;
	for(i=20;i>=0;i--) {
		if(L-1-(B+(1<<i))>=0 && R+(B+(1<<i))<N) {
			auto h1=rh[0].hash(L-1-(B+(1<<i)),(L-1));
			auto h2=rh[1].hash(N-1-(R+(B+(1<<i))),N-1-R);
			if(h1==h2) B+=1<<i;
		}
		if(L-(C+(1<<i))>=0 && R+1+(C+(1<<i))<N) {
			auto h1=rh[0].hash(L-(C+(1<<i)),L);
			auto h2=rh[1].hash(N-1-(R+1+(C+(1<<i))),N-1-(R+1));
			if(h1==h2) C+=1<<i;
		}
	}
	return max({A+B+1,A+C+1});
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	T=S;
	reverse(ALL(T));
	
	rh[0].init(S);
	rh[1].init(T);
	
	int ma=0;
	FOR(i,N) {
		ma=max(ma,2*hoge(i,i)+1);
		if(i && S[i]==S[i-1]) ma=max(ma,2*hoge(i-1,i)+2); 
	}
	cout<<min(N-1,ma)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
