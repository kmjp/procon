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

const ll mo0=1000000021,mo1=1000000009;
ll mul0,mul1;
const ll add0=1000010007, add1=1003333331;
vector<ll> pmo[2];
vector<ll> hash_[2];
struct RollingHash {
	vector<int> s; int l; 
	void init(vector<int> s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
	}

	pair<ll,ll> hash(int l,int r) { // s[l..r]
		if(l>r) return make_pair(0,0);
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0,
			             (hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
	static pair<ll,ll> concat(pair<ll,ll> L,pair<ll,ll> R,int RL) { // hash(L+R) RL=len-of-R
		while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((R.first + L.first*pmo[0][RL])%mo0,(R.second + L.second*pmo[1][RL])%mo1);
	}
};

int N,K;
vector<int> P;

int NV=1<<20;
vector<pair<pair<ll,ll>,int>> val;

pair<pair<ll,ll>,int> comp(pair<pair<ll,ll>,int>& A,pair<pair<ll,ll>,int>& B) {
	int L=A.second+B.second;
	pair<ll,ll> P=RollingHash::concat(A.first,B.first,B.second);
	return {P,L};
}

void update(int entry, pair<pair<ll,ll>,int> v) {
	entry += NV;
	val[entry]=v;
	while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	mul0=10009+(((ll)&mul0)>>5)%259,mul1=10007+(((ll)&mul1)>>5)%257;
	pmo[0].push_back(1),pmo[1].push_back(1);
	
	val.resize(2*NV);
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x;
		P.push_back(x);
	}
	RollingHash rh;
	rh.init(P);
	
	set<pair<ll,ll>> S;
	
	FOR(i,K-1) update(P[i],make_pair(make_pair(P[i]+add0,P[i]+add1),1));
	for(i=0;i+K<=N;i++) {
		update(P[i+K-1],make_pair(make_pair(P[i+K-1]+add0,P[i+K-1]+add1),1));
		auto HL=rh.hash(0,i-1);
		auto HM=val[1];
		auto HR=rh.hash(i+K,N-1);
		
		HR=RollingHash::concat(HM.first,HR,N-i-K);
		HL=RollingHash::concat(HL,HR,N-i);
		S.insert(HL);
		update(P[i],make_pair(make_pair(0,0),0));
	}
	
	cout<<S.size()<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
