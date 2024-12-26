#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll N,L,T,Q;

ll A[101010],S[101010],D[101010],E[101010];
const ll mo=1000000007;

int delid[101010];
int id[101010],rid[101010];
const int DI=350;
int alive[DI*DI];
int num[DI+1];
vector<int> As[DI+1],Es[DI+1];
ll DS[DI+1];
ll ret=0;

void add(int v) {
	int p=rid[v];
	int block=v/DI;
	int i;
	FOR(i,block) {
		(ret+=D[p]*num[i]-DS[i])%=mo;
		ret-=lower_bound(ALL(As[i]),A[p]+1)-As[i].begin();
		ret+=lower_bound(ALL(Es[i]),E[p]+1)-Es[i].begin();
	}

	for(i=block+1;i<DI;i++) {
		(ret+=DS[i]-D[p]*num[i])%=mo;
		ret-=As[i].end()-lower_bound(ALL(As[i]),A[p]);
		ret+=Es[i].end()-lower_bound(ALL(Es[i]),E[p]);
	}
	for(i=block*DI;i<(block+1)*DI;i++) if(alive[i]) {
		if(i<v) {
			if(A[rid[i]]<=A[p]) ret--;
			if(E[rid[i]]<=E[p]) ret++;
			ret+=D[p]-D[rid[i]];
		}
		else {
			if(A[rid[i]]>=A[p]) ret--;
			if(E[rid[i]]>=E[p]) ret++;
			ret+=D[rid[i]]-D[p];
		}
	}
	alive[v]=1;
	As[block].push_back(A[p]);
	Es[block].push_back(E[p]);
	sort(ALL(As[block]));
	sort(ALL(Es[block]));
	(DS[block]+=D[p])%=mo;
	num[block]++;
}
void del(int v) {
	int p=rid[v];
	int block=v/DI;
	alive[v]=0;
	int i,x;

	FOR(i,block) {
		(ret-=D[p]*num[i]-DS[i])%=mo;
		ret+=lower_bound(ALL(As[i]),A[p]+1)-As[i].begin();
		ret-=lower_bound(ALL(Es[i]),E[p]+1)-Es[i].begin();
	}

	for(i=block+1;i<DI;i++) {
		(ret-=DS[i]-D[p]*num[i])%=mo;
		ret+=As[i].end()-lower_bound(ALL(As[i]),A[p]);
		ret-=Es[i].end()-lower_bound(ALL(Es[i]),E[p]);
	}
	for(i=block*DI;i<(block+1)*DI;i++) if(alive[i]) {
		if(i<v) {
			if(A[rid[i]]<=A[p]) ret++;
			if(E[rid[i]]<=E[p]) ret--;
			ret-=D[p]-D[rid[i]];
		}
		else {
			if(A[rid[i]]>=A[p]) ret++;
			if(E[rid[i]]>=E[p]) ret--;
			ret-=D[rid[i]]-D[p];
		}
	}

	alive[v]=0;
	FOR(i,As[block].size()) if(As[block][i]==A[p]) {
		swap(As[block][i],As[block].back());
		As[block].pop_back();
		sort(ALL(As[block]));
		break;
	}
	FOR(i,Es[block].size()) if(Es[block][i]==E[p]) {
		swap(Es[block][i],Es[block].back());
		Es[block].pop_back();
		sort(ALL(Es[block]));
		break;
	}
	(DS[block]+=mo-D[p])%=mo;
	num[block]--;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>T;
	vector<pair<int,int>> Ss;
	map<pair<int,int>,int> ids;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		cin>>S[i];
		ids[{A[i],S[i]}]=i;
		Ss.push_back({S[i],i});
	}
	MINUS(delid);
	cin>>Q;
	FOR(i,Q) {
		cin>>A[i+N]>>S[i+N];
		if(ids.count({A[i+N],S[i+N]})) {
			delid[i+N]=ids[{A[i+N],S[i+N]}];
			ids.erase({A[i+N],S[i+N]});
		}
		else {
			ids[{A[i+N],S[i+N]}]=i+N;
			Ss.push_back({S[i+N],i+N});
		}
	}
	FOR(i,N+Q) {
		D[i]=(A[i]+S[i]*T)/L%mo;
		E[i]=(A[i]+S[i]*T)%L;
	}
	sort(ALL(Ss));
	FOR(i,Ss.size()) {
		rid[i]=Ss[i].second;
		id[Ss[i].second]=i;
	}
	
	FOR(i,N+Q) {
		if(delid[i]==-1) {
			add(id[i]);
		}
		else {
			x=delid[i];
			del(id[x]);
			
		}
		
		
		if(i>=N) cout<<(ret%mo+mo)%mo<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
