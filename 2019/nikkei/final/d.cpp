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

ll tree_normalize(vector<ll> T) {
	static ll momo[2]={1000000007,1000000009};
	static vector<ll> prim = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79};
	
	sort(ALL(T));
	int id=0,id2=1;
	ll a=1,b=1;
	FORR(r,T) {
		ll h=r>>32, l=r-(h<<32);
		(a+=h*prim[(id++)%prim.size()])%=momo[0];
		(b+=l*prim[(id2++)%prim.size()])%=momo[1];
	}
	return (a<<32)+b;
}

ll V[2][101010];

int N[2];
vector<int> E[2][202020];
vector<int> cand[2];
set<int> ret;

int dfs_center(int cur,int pre,int id) {
	int num=1;
	int ma=0;
	
	FORR(r,E[id][cur]) if(r!=pre) {
		int res=dfs_center(r,cur,id);
		ma=max(ma,res);
		num+=res;
	}
	if(ma*2<=N[id]&&(N[id]-num)*2<=N[id]) cand[id].push_back(cur);
	
	
	
	return num;
}

ll dfs_hash(int cur,int pre,int id) {
	vector<ll> H;
	FORR(e,E[id][cur]) if(e!=pre) H.push_back(dfs_hash(e,cur,id));
	V[id][cur]=tree_normalize(H);
	return V[id][cur];
}

void dfs_check(int c0,int c1,int p0,int p1) {
	if(E[0][c0].size()==E[1][c1].size()+1) {
		map<ll,int> M;
		FORR(e,E[0][c0]) if(e!=p0) M[V[0][e]]++;
		FORR(e,E[1][c1]) if(e!=p1) {
			if(M[V[1][e]]==0) return;
			M[V[1][e]]--;
		}
		ll tar=0;
		FORR(m,M) if(m.second) tar=m.first;
		FORR(e,E[0][c0]) if(e!=p0 && E[0][e].size()==1&&V[0][e]==tar) ret.insert(e);
	}
	else if(E[0][c0].size()==E[1][c1].size()) {
		map<ll,int> M;
		FORR(e,E[0][c0]) if(e!=p0) M[V[0][e]]++;
		int dif=-1;
		FORR(e,E[1][c1]) if(e!=p1) {
			if(M[V[1][e]]==0) {
				if(dif!=-1) return;
				dif=e;
			}
			else {
				M[V[1][e]]--;
			}
		}
		ll tar=0;
		FORR(m,M) if(m.second) tar=m.first;
		FORR(e,E[0][c0]) if(e!=p0 && V[0][e]==tar) dfs_check(e,dif,c0,c1);
	}

}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N[1];
	N[0]=N[1]+1;
	FOR(j,2) {
		FOR(i,N[j]-1) {
			cin>>x;
			E[j][i].push_back(x-1);
			E[j][x-1].push_back(i);
		}
	}
	FOR(i,2) {
		dfs_center(0,-1,i);
	}
	assert(cand[0].size()<=2);
	assert(cand[1].size()<=2);
	
	FORR(c0,cand[0]) FORR(c1,cand[1]) {
		dfs_hash(c0,-1,0);
		dfs_hash(c1,-1,1);
		dfs_check(c0,c1,-1,-1);
	}
	FORR(r,ret) cout<<(r+1)<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
