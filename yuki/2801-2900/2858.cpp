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
int N,M;
string S;
using VT = string;

struct RollingHash {
	static const ll mo0=1000000021,mo1=1000000009;
	static ll mul0,mul1;
	static const ll add0=1000010007, add1=1003333331;
	static vector<ll> pmo[2];
	VT s; int l; vector<ll> hash_[2];
	void init(VT s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0+time(NULL))>>5)%1259,mul1=10007+(time(NULL)+((ll)&mul1)>>5)%2257;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
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
	pair<ll,ll> hash(VT s) { init(s); return hash(0,s.size()-1); }
	static pair<ll,ll> concat(pair<ll,ll> L,pair<ll,ll> R,int RL) { // hash(L+R) RL=len-of-R
		while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((R.first + L.first*pmo[0][RL])%mo0,(R.second + L.second*pmo[1][RL])%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;
RollingHash rh1,rh2;

int maxpal(string v) {
	string w=v;
	reverse(ALL(w));
	rh1.init(v);
	rh2.init(w);
	int i;
	for(i=0;i+M<=v.size();i++) {
		if(rh1.hash(i,i+M-1)==rh2.hash(v.size()-1-(i+M-1),v.size()-1-i)) return 1;
	}
	for(i=0;i+M+1<=v.size();i++) {
		if(rh1.hash(i,i+M-1+1)==rh2.hash(v.size()-1-(i+M-1+1),v.size()-1-i)) return 1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>S;
		if(maxpal(S)) {
			cout<<1<<endl;
			continue;
		}
		if(maxpal(S+S)) {
			cout<<2<<endl;
			continue;
		}
		if(maxpal(S+S+S)) {
			cout<<3<<endl;
			continue;
		}
		S=S+S+S;
		rh1.init(S);
		s=S;
		reverse(ALL(s));
		rh2.init(s);
		ll mi=1<<30;
		for(i=N;i<2*N;i++) {
			if(rh1.hash(i-N,i+N)==rh2.hash(3*N-1-(i+N),3*N-1-(i-N))) {
				ll L,R;
				if(M%2==1) {
					L=i-M/2+(1LL<<30)*N;
					R=i+M/2+(1LL<<30)*N;;
				}
				else {
					L=i-(M+1)/2+(1LL<<30)*N;
					R=i+(M+1)/2+(1LL<<30)*N;;
				}
				L/=N;
				R/=N;
				mi=min(mi,R-L+1);
			}
		}
		for(i=N;i<2*N;i++) {
			if(rh1.hash(i-(N-1),i+N)==rh2.hash(3*N-1-(i+N),3*N-1-(i-(N-1)))) {
				ll L,R;
				if(M%2==0) {
					L=i-(M/2-1)+(1LL<<30)*N;
					R=i+M/2+(1LL<<30)*N;;
				}
				else {
					L=i-((M+1)/2-1)+(1LL<<30)*N;
					R=i+(M+1)/2+(1LL<<30)*N;;
				}
				L/=N;
				R/=N;
				mi=min(mi,R-L+1);
			}
		}
		if(mi==1<<30) mi=-1;
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
