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

int N,Q;
vector<int> MP;
string S[101010];
int L[101010];
int R[101010];
int V[101010];

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

ll SP[2][202020];
ll mo[2]={1000000007,1000000009};


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	srand(clock());
	FOR(i,201000) {
		SP[0][i+1]=(SP[0][i]+prime[rand()%10000+10000])%mo[0];
		SP[1][i+1]=(SP[1][i]+prime[rand()%20000+20000])%mo[1];
	}
	
	
	MP.push_back(-1);
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>S[i];
		if(S[i]=="!") {
			cin>>L[i]>>R[i]>>V[i];
			MP.push_back(L[i]);
			MP.push_back(R[i]);
		}
	}
	sort(ALL(MP));
	MP.erase(unique(ALL(MP)),MP.end());
	map<pair<ll,ll>,int> memo;
	
	ll v[2]={0,0};
	memo[{v[0],v[1]}]=0;
	FOR(i,Q) {
		if(S[i]=="!") {
			L[i]=lower_bound(ALL(MP),L[i])-MP.begin();
			R[i]=lower_bound(ALL(MP),R[i])-MP.begin();
			FOR(x,2) {
				v[x]+=(SP[x][R[i]]-SP[x][L[i]])*V[i];
				v[x]=(v[x]%mo[x]+mo[x])%mo[x];
			}
			if(memo.count({v[0],v[1]})==0) memo[{v[0],v[1]}]=i+1;
		}
		else {
			cout<<memo[{v[0],v[1]}]<<endl;
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
