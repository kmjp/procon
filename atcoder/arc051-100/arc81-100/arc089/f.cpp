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


ll comb(int P_,int Q_) {
	static const int N_=1020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);};

int N,K;
string S;
ll mo=1000000007;
ll group[71][71];
int ML[71];
ll fact[72],factr[72],inv[72];
ll tot;
vector<int> G;

void hoge(vector<int> V,vector<ll> C) {
	vector<int> O=V;
	string T=S;
	int TN=T.size(),VN=V.size();
	vector<int> R(VN,-1);
	
	int x=0,y=0,i;
	FOR(i,TN) if(T[i]=='r' && x<VN) {
		R[x]=i;
		V[x]--;
		x++;
		T[i]='_';
		
	}
	if(x!=VN) return;
	x=0;
	FOR(i,TN) if(T[i]=='b') {
		if(x<VN && V[x] && i>R[x]) {
			V[x]--;
			R[x]=i;
			x++;
			T[i]='_';
		}
	}
	if(x<VN && V[x]) return;
	
	x=0;
	FOR(i,TN) if(T[i]!='_') {
		if(x<VN && V[x] && i>R[x]) {
			V[x]--;
			T[i]='_';
			if(V[x]==0) x++;
		}
	}
	if(x<VN && V[x]) return;
	
	map<int,int> M;
	FORR(c,O) M[c]++;
	
	ll ret=0;
	FOR(x,N+1) {
		int left=N-x-(V.size()-1);
		if(left<0) break;
		(ret+=C[x]*hcomb(V.size()+1,left))%=mo;
	}
	
	(ret*=fact[V.size()])%=mo;
	FORR(m,M) (ret*=factr[m.second])%=mo;
	
	(tot+=ret)%=mo;
}

void dfs(int L,int cur,vector<ll> C) {
	if(cur==0) return;
	// not take cur
	dfs(L,cur-1,C);
	
	if(L>=ML[cur]) {
		G.push_back(cur);
		vector<ll> C2(71);
		for(int x=0;x<=70;x++) if(C[x]) {
			for(int y=ML[cur];x+y<=70;y++) {
				(C2[x+y]+=C[x]*group[cur][y])%=mo;
			}
		}
		
		hoge(G,C2);
		dfs(L-(ML[cur]+1),cur,C2);
		G.pop_back();
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=70;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=70;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	for(i=1;i<=70;i++) group[1][i]=1;
	ML[1]=1;
	for(i=2;i<=70;i++) {
		vector<int> cand={(i-1)*2-1,(i-1)*2,(i-1)*2,(i-1)*2+1};
		ML[i]=(i-1)*2-1;
		FORR(l,cand) {
			for(x=l;x<=70;x++) (group[i][x]+=hcomb(l,x-l))%=mo;
		}
	}
	
	
	tot=1;
	vector<ll> C(71);
	C[0]=1;
	dfs(N,70,C);
	cout<<tot<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
