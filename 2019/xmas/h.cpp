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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> L,R,G;
	
	SegTree_1(){
		L=vector<V>(NV*2,-1);
		R=vector<V>(NV*2,-1);
		G=vector<V>(NV*2,-1);
	};
	void update(int e) {
		if(L[2*e]==-1) {
			L[e]=L[2*e+1];
			R[e]=R[2*e+1];
			G[e]=G[2*e+1];
		}
		else if(L[2*e+1]==-1) {
			L[e]=L[2*e];
			R[e]=R[2*e];
			G[e]=G[2*e];
		}
		else {
			L[e]=L[2*e];
			R[e]=R[2*e+1];
			G[e]=__gcd(__gcd(G[2*e],G[2*e+1]),L[2*e+1]-R[2*e]);
		}
		
	}
	
	void white(int entry) {
		entry += NV;
		L[entry]=R[entry]=entry-NV;
		G[entry]=0;
		while(entry>1) entry>>=1, update(entry);
	}
	void black(int entry) {
		entry += NV;
		L[entry]=R[entry]=-1;
		G[entry]=-1;
		while(entry>1) entry>>=1, update(entry);
	}
};

int H,W;
SegTree_1<int,1<<18> st;

const int prime_max = 100000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

int hoge(string S) {
	int ret=0;
	vector<int> V;
	int x,i=101010;
	int cnt=0;
	FOR(x,W) {
		if(S[x]=='.') {
			cnt++;
			i=min(i,x);
			st.white(x);
		}
		else {
			st.black(x);
		}
	}
	if(i==101010) return 0;
	int g=st.G[1];
	if(g==0) return 1;
	while(g%2==0) g/=2;
	if(g>1) return 1;
	
	if(cnt<=2) return cnt;
	FOR(x,NP) if(x>0) {
		if(x>1 && i+prime[x-1]>=W) break;
		for(int j=i;j<W;j+=prime[x]) {
			st.black(j);
		}
		int g=st.G[1];
		if(g==0) return 2;
		while(g%2==0) g/=2;
		if(g>1) return 2;
		for(int j=i;j<W;j+=prime[x]) {
			if(S[j]=='.') st.white(j);
		}
	}
	return 3;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	cin>>H>>W;
	int ret=0;
	FOR(y,H) {
		string S;
		cin>>S;
		ret+=hoge(S);
	}
	cout<<ret<<endl;

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
