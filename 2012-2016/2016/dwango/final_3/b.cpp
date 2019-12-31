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
ll mo=1000000007;
int X[101010];
vector<pair<int,int>> E[101010];
int num[101010];
int rev[2010100];
int last[101010];
int L[101010],R[101010];
ll ret[101010];
const int DIV=400;
vector<pair<int,int>> ev[404];
int cur;

int id;
vector<int> up;

vector<pair<int,int>> enumpr(ll n) {
	map<int,int> M;
	for(int i=2;i*i<=n;i++) while(n%i==0) M[i]++,n/=i;
	if(n>1) M[n]++;
	vector<pair<int,int>> V;
	FORR(r,M) V.push_back({r.first,r.second});
	return V;
}

inline int mulmod(int a,int b,int mo) {
	int d,r;
	if(a==0 || b==0) return 0;
	if(a==1 || b==1) return max(a,b);
	__asm__("mull %4;"
	        "divl %2"
		: "=d" (r), "=a" (d)
		: "r" (mo), "a" (a), "d" (b));
	return r;
}

void add(int x) {
	FORR(r,E[X[x]]) {
		if(last[r.first]!=id) {
			cur=mulmod(cur,rev[num[r.first]],mo);
			last[r.first]=id;
			up.push_back(r.first);
		}
		num[r.first] += r.second;
	}
}
void del(int x) {
	FORR(r,E[X[x]]) {
		if(last[r.first]!=id) {
			cur=mulmod(cur,rev[num[r.first]],mo);
			last[r.first]=id;
			up.push_back(r.first);
		}
		num[r.first] -= r.second;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=100000;i++) {
		E[i]=enumpr(i);
		num[i]=1;
	}
	rev[1]=1;
	for(i=2;i<=2000000;i++) rev[i] = 1LL*rev[mo % i] * (mo - mo / i) % mo;
	
	cin>>N>>Q;
	FOR(i,N) cin>>X[i];
	
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--,R[i]--;
		ev[L[i]/DIV].push_back({R[i],i});
	}
	
	MINUS(last);
	
	int LL=0,RR=-1;
	cur=1;
	FOR(i,304) if(ev[i].size()) {
		sort(ALL(ev[i]));
		FORR(r,ev[i]) {
			x = r.second;
			id=x;
			up.clear();
			
			while(L[x]<LL) add(--LL);
			while(RR<=R[x]) add(RR++);
			while(LL<L[x]) del(LL++);
			while(R[x]+1<RR) del(--RR);
			FORR(t,up) {
				cur=mulmod(cur,num[t],mo);
			}
			ret[x]=cur;
		}
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
