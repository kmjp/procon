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
int C[1202020];
int R[1202020];
int RC[1202020];
map<int,int> num;
vector<int> P[1202020];

void hoge(vector<pair<int,int>> V) {
	ZERO(RC);
	int i;
	FOR(i,M+1) P[i].clear();
	RC[M]=-2;
	FORR(v,V) {
		RC[v.first]++;
		RC[v.second]++;
		P[v.first].push_back(v.second);
		P[v.second].push_back(v.first);
	}
	
	num.clear();
	num[0]=10101010;
	FOR(i,M+1) num[RC[i]]++;
	
	FOR(i,M) {
		int dif=0;
		int difsum=N-RC[i];
		
		num[RC[i]]--;
		FORR(p,P[i]) {
			if(p!=i) {
				difsum--;
				num[RC[p]]--;
				RC[p]--;
				num[RC[p]]++;
				dif++;
			}
		}
		while(num.rbegin()->second==0) num.erase(num.rbegin()->first);
		dif+=difsum-num.rbegin()->first;
		R[i]=min(R[i],dif);
		num[RC[i]]++;
		FORR(p,P[i]) {
			if(p!=i) {
				num[RC[p]]--;
				RC[p]++;
				num[RC[p]]++;
			}
		}
	}
	

}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	if(M==1) return _P("0\n");
	C[0]=M;
	FOR(i,N) {
		cin>>C[i+1];
		C[i+1]--;
		R[i]=1<<20;
	}
	C[N+1]=M;
	
	vector<pair<int,int>> V[2];
	for(i=1;i<=N;i+=2) V[0].push_back({C[i],C[i+1]});
	for(i=0;i<=N;i+=2) V[1].push_back({C[i],C[i+1]});
	
	
	hoge(V[0]);
	hoge(V[1]);
	FOR(i,M) cout<<R[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
