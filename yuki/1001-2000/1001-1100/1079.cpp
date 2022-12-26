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

int N,K;
int A[101010];

map<int,ll> C[101010],P[101010];
set<int> dead;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	A[0]=A[N+1]=1<<30;
	map<int,vector<int>> M;
	FOR(i,N) {
		cin>>A[i+1];
		M[A[i+1]].push_back(i+1);
		C[N+1][A[i+1]]++;
		P[N+1][A[i+1]]+=i+1;
	}
	
	dead.insert(0);
	dead.insert(N+1);
	
	ll ret=0;
	FORR(m,M) {
		reverse(ALL(m.second));
		FORR(v,m.second) {
			dead.insert(v);
			auto it=dead.find(v);
			int L=*prev(it);
			int R=*next(it);
			
			if(v-L>R-v) {
				swap(C[R],C[v]);
				swap(P[R],P[v]);
				for(i=v+1;i<R;i++) {
					C[v][A[i]]--;
					P[v][A[i]]-=i;
					C[R][A[i]]++;
					P[R][A[i]]+=i;
				}
				C[v][A[v]]--;
				P[v][A[v]]-=v;
			}
			else {
				for(i=L+1;i<v;i++) {
					C[R][A[i]]--;
					P[R][A[i]]-=i;
					C[v][A[i]]++;
					P[v][A[i]]+=i;
				}
				C[R][A[v]]--;
				P[R][A[v]]-=v;
			}
		}
		FORR(v,m.second) {
			auto it=dead.find(v);
			int L=*prev(it);
			int R=*next(it);
			
			if(v-L>R-v) {
				C[v][A[v]]++;
				P[v][A[v]]+=v;
				for(i=v;i<R;i++) ret+=(i+1)*C[v][K-A[i]]-P[v][K-A[i]];
				C[v][A[v]]--;
				P[v][A[v]]-=v;
			}
			else {
				C[R][A[v]]++;
				P[R][A[v]]+=v;
				for(i=L+1;i<=v;i++) ret+=P[R][K-A[i]]-(i-1)*C[R][K-A[i]];
				C[R][A[v]]--;
				P[R][A[v]]-=v;
			}
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
