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

int N,M;
int A[51],B[51],C[51],MA;
ll fact[111];
ll mo=1000000007;
vector<int> P[121];

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll getpat(int len,set<int> pos[51],set<int> cand[51]) {
	int i,f=0;
	vector<pair<int,int>> V;
	V.push_back({-1,-1});
	FOR(i,N) {
		if(pos[i].size()>1 || cand[i].size()>1) return 0;
		if(i<len && cand[i].size()) V.push_back({i,*cand[i].begin()});
	}
	V.push_back({len,N});
	
	ll ret=1;
	FOR(i,V.size()-1) {
		if(V[i].second>=V[i+1].second) return 0;
		int c=0;
		for(int x=V[i].second+1;x<V[i+1].second;x++) if(pos[x].empty()) c++;
		(ret*=comb(c,V[i+1].first-V[i].first-1))%=mo;
	}
	for(i=len;i<N;i++) if(cand[i].empty()) f++;
	return ret*fact[f]%mo;
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	
	fact[0]=1;
	for(i=1;i<=100;i++) fact[i]=fact[i-1]*i%mo;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		B[i]--;
		C[i]--;
		MA=max(MA,A[i]);
	}
	
	if(MA==0) {
		set<int> pos[51],cand[51];
		FOR(i,M) {
			pos[C[i]].insert(B[i]);
			cand[B[i]].insert(C[i]);
		}
		int f=0;
		FOR(i,N) {
			if(pos[i].size()>1) return _P("0\n");
			if(cand[i].size()>1) return _P("0\n");
			if(pos[i].empty()) f++;
		}
		cout<<fact[f]<<endl;
		return;
	}
	
	ll ret=0;
	FOR(x,N) {
		set<vector<int>> S;
		for(y=1;y<N-x;y++) {
			FOR(i,111) P[i].clear();
			P[55].push_back(y);
			FOR(i,N-x) if(i!=y) P[55].push_back(i);
			
			for(i=56;i<=110;i++) {
				P[i]=P[i-1];
				next_permutation(ALL(P[i]));
				if(P[i]<=P[55]) {
					P[i].clear();
					break;
				}
			}
			for(i=54;i>=0;i--) {
				P[i]=P[i+1];
				prev_permutation(ALL(P[i]));
				if(P[i]>=P[55]) {
					P[i].clear();
					break;
				}
			}
			
			for(int z=1;z<=MA;z++) {
				if(P[55-z].empty()) continue;
				if(P[55-z+MA].empty()) continue;
				if(S.count(P[55-z])) continue;
				S.insert(P[55-z]);
				
				set<int> pos[51],cand[51];
				FOR(i,M) {
					int tar;
					
					if(B[i]>=x) {
						tar=P[55-z+A[i]][B[i]-x];
					}
					else {
						tar=(N-x)+B[i];
					}
					pos[C[i]].insert(tar);
					cand[tar].insert(C[i]);
				}
				(ret+=getpat(N-x,pos,cand))%=mo;
			}
			
		}
	}
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
