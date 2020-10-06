#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[101];
const ll mo=1000000007;
vector<int> V;
ll ret=0;

vector<int> LIS(vector<int>& v) {
	int i,N=v.size();
	vector<int> dp(N,1<<30),id(N);
	FOR(i,v.size()) {
		id[i] = lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin();
		// id[i] = lower_bound(dp.begin(),dp.end(),v[i]+1) - dp.begin(); //‚±‚¤‚·‚é‚Æ“¯‚¶’l‚à‹–—e‚·‚é
		dp[id[i]] = v[i];
	}
	int nl = *max_element(id.begin(),id.end());
	vector<int> ret(nl+1);
	FOR(i,N) if(id[N-1-i] == nl) ret[nl--] = v[N-1-i];
	return ret;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(int P_,int Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	ll p=1,q=1;
	Q_=min(Q_,P_-Q_);
	for(int i=1;i<=Q_;i++) p=p*P_%mo, q=q*i%mo,P_--;
	
	return p*modpow(q,mo-2)%mo;
}


ll hoge(vector<int>& P,int ma,vector<int>& Q) {
	if(Q.size()<=ma) {
		ll ret=0;
		for(int i=(Q.empty()?0:Q.back());i<V.size();i++) {
			Q.push_back(i);
			ret+=hoge(P,ma,Q);
			Q.pop_back();
		}
		return ret%mo;
	}
	
	int ok=1;
	int i;
	int num[7]={};
	FORR(q,Q) num[q]++;
	FOR(i,N) {
		int tar=Q[P[i]];
		if(V[tar]>A[i]) return 0;
	}
	int pre=0;
	ll pat=1;
	FOR(i,V.size()) {
		int cur=V[i]-pre;
		if(num[i]>cur) return 0;
		pat=pat*comb(cur,num[i])%mo;
		pre=V[i];
	}
	/*
	cout<<"!"<<endl;
	FORR(p,P) cout<<p;
	cout<<" ";
	FORR(q,Q) cout<<q;
	cout<<" "<<pat<<endl;
	*/
	
	return pat;
}

void go(vector<int>& P) {
	int lis=LIS(P).size();
	int ma=*max_element(ALL(P));
	vector<int> Q;
	ll pat=hoge(P,ma,Q);
	//FORR(p,P) cout<<p;
	//if(pat) cout<<" "<<lis<<" "<<pat<<endl;
	(ret+=lis*pat)%=mo;
	
}

void dfs(int cur,vector<int>& P) {
	if(cur==N) {
		set<int> S;
		FORR(p,P) S.insert(p);
		int gr=0;
		while(S.count(gr)) gr++;
		if(S.size()==gr) {
			go(P);
		}
		return;
	}
	for(int i=0;i<=5;i++) {
		P.push_back(i);
		dfs(cur+1,P);
		P.pop_back();
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		V.push_back(A[i]);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	vector<int> P;
	dfs(0,P);
	
	FOR(i,N) ret=ret*modpow(A[i])%mo;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
