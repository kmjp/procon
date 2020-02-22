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
vector<ll> C[404];
ll VV[404];
int R[404];
map<ll,int> B[5];

ll getkey(vector<ll> v) {
	ll r=1LL<<60;
	int i;
	FOR(i,4) {
		rotate(v.begin(),v.begin()+1,v.end());
		r=min(r,v[0]*1000000000+v[1]*1000000+v[2]*1000+v[3]);
	}
	return r;
}

ll dfs(int cur,int n1,int n2,int n4) {
	if(cur==0) return 1;
	ll ret=0;
	if(n1) ret += n1*dfs(cur-1,n1-1,n2,n4);
	if(n2) ret += 2*n2*dfs(cur-1,n1,n2-1,n4);
	if(n4) ret += 4*n4*dfs(cur-1,n1,n2,n4-1);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	FOR(i,N) {
		vector<ll> V(4,0);
		FOR(j,4) cin>>V[j];
		C[i]=V;
		VV[i]=getkey(C[i]);
		R[i]=1;
		if(C[i][0]==C[i][2]&&C[i][1]==C[i][3]) {
			R[i]=2;
			if(C[i][0]==C[i][1]) R[i]=4;
		}
		B[R[i]][VV[i]]++;
	}
	ll ret=0;
	FOR(x,N) {
		B[R[x]][VV[x]]--;
		for(y=x+1;y<N;y++) {
			B[R[y]][VV[y]]--;
			FOR(z,4) {
				
				map<ll,int> mp;
				mp[getkey({C[x][1],C[x][0],C[y][1],C[y][0]})]++;
				mp[getkey({C[x][2],C[x][1],C[y][0],C[y][3]})]++;
				mp[getkey({C[x][3],C[x][2],C[y][3],C[y][2]})]++;
				mp[getkey({C[x][0],C[x][3],C[y][2],C[y][1]})]++;
				
				ll tmp=1;
				FORR(r,mp) {
					tmp *= dfs(r.second,B[1][r.first],B[2][r.first],B[4][r.first]);
					if(tmp==0) break;
				}
				ret += tmp;
				
				rotate(C[y].begin(),C[y].begin()+1,C[y].end());
				
			}
			B[R[y]][VV[y]]++;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
