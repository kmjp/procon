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

int N,A,B,Q;
ll P[404040];

vector<vector<ll>> S;

vector<ll> merge(vector<ll> L,vector<ll> R) {
	int NL=L.size(),NR=R.size();
	vector<ll> X={-1LL<<60};
	
	int CL=0,CR=0;
	while(CL<NL||CR<NR) {
		if(CL==NL) {
			addr:
			X.push_back(R[CR]-1LL*(NL-CL)*A);
			CR++;
		}
		else if(CR==NR) {
			addl:
			X.push_back(max(X.back()+A, L[CL]-1LL*CR*B));
			CL++;
		}
		else {
			ll vl=L[CL]-1LL*CR*B;
			ll vr=R[CR]-1LL*(NL-CL)*A;
			if(vl<vr) goto addl;
			else goto addr;
		}
	}
	X.erase(X.begin());
	return X;
}

void add(vector<ll> p) {
	if(S.empty()||S.back().size()!=p.size()) {
		S.push_back(p);
	}
	else {
		p=merge(S.back(),p);
		S.pop_back();
		add(p);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	FOR(i,N) {
		cin>>x;
		vector<ll> P={x};
		add(P);
		
	}
	
	
	cin>>Q;
	int NQ=0;
	while(Q--) {
		cin>>x;
		if(x==1) {
			cin>>x;
			vector<ll> P={x};
			add(P);
		}
		else {
			ll X;
			cin>>X;
			FORR(s,S) {
				if(s[0]>=X) {
					X+=s.size()*A;
				}
				else if(X-((ll)s.size()-1)*B>s.back()) {
					X-=1LL*s.size()*B;
				}
				else {
					int L=0;
					for(i=20;i>=0;i--) if(L+(1<<i)<=s.size()&&X-((1LL<<i)-1)*B>s[L+((1LL<<i)-1)]) {
						L+=1<<i;
						X-=(1LL<<i)*B;
					}
					X+=1LL*(s.size()-L)*A;
				}
			}
			cout<<X<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
