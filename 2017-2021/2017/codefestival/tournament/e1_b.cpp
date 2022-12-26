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

int N;
int U[101010],V[101010];
vector<int> E[101010];
map<pair<int,int>,int> M;
ll S[101010];
ll ret[101010];
int C[101010];
int D[101010];

int dfs(int cur,int pre,int d) {
	C[cur]=1;
	D[cur]=d;
	FORR(e,E[cur]) if(e!=pre) {
		C[cur]+=dfs(e,cur,d+1);
	}
	
	if(C[cur]!=N-C[cur] && pre!=-1) {
		ret[M[{cur,pre}]]=(S[cur]-S[pre])/(N-2*C[cur]);
	}
	return C[cur];
}

ll dfs2(int cur,int pre,ll sum) {
	ll tmp=sum;
	FORR(e,E[cur]) if(e!=pre) {
		tmp+=dfs2(e,cur,sum+ret[M[make_pair(cur,e)]]);
	}
	return tmp;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
		M[{U[i],V[i]}]=M[{V[i],U[i]}]=i;
	}
	FOR(i,N) cin>>S[i];
	
	dfs(0,-1,0);
	
	FOR(i,N-1) {
		if(ret[i]==0) {
			ll tmp;
			if(D[U[i]]>D[V[i]]) {
				tmp=dfs2(U[i],-1,0);
				ret[i]=(S[U[i]]-tmp)/(N-C[U[i]]);
			}
			else {
				tmp=dfs2(V[i],-1,0);
				ret[i]=(S[V[i]]-tmp)/(N-C[V[i]]);
			}
			
		}
		cout<<ret[i]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
