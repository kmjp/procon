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
vector<int> E[1010];
int R[1010];
ll X[1010],Y[1010];
int visv[1010],visp[1010];
int C[1010];

void dfs(int v,int p,int dx,int dy,vector<int> S) {
	R[v]=p+1;
	visv[v]=visp[p]=1;
	
	vector<pair<double,int>> V;
	int i;
	FORR(s,S) {
		double pvx=X[s]-X[p];
		double pvy=Y[s]-Y[p];
		double d=hypot(pvx,pvy);
		pvx/=d;
		pvy/=d;
		V.push_back({dx*pvx+dy*pvy,s});
		assert(dx*pvy-dy*pvx<=0);
	}
	sort(ALL(V));
	reverse(ALL(V));
	int cur=0;
	FORR(e,E[v]) if(visv[e]==0) {
		vector<int> S2;
		int pn;
		FOR(i,C[e]) {
			if(i==0) pn=V[cur].second;
			else S2.push_back(V[cur].second);
			cur++;
		}
		dfs(e,pn,X[pn]-X[p],Y[pn]-Y[p],S2);
	}
	
}

int dfsc(int cur,int pre) {
	C[cur]=1;
	FORR(r,E[cur]) if(r!=pre) C[cur]+=dfsc(r,cur);
	return C[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	srand(time(NULL));
	int st=0;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		//X[i]=rand()%1001;
		//Y[i]=rand()%1001;
		if(X[i]<X[st] || (X[i]==X[st]&&Y[i]<Y[st])) st=i;
	}
	
	dfsc(0,-1);
	vector<int> S;
	FOR(i,N) if(i!=st) S.push_back(i);
	dfs(0,st,0,1,S);
	
	FOR(i,N) assert(R[i]>0);
	FOR(i,N) assert(count(R,R+N,i+1)==1);
	
	//FOR(i,N) _P("%d %d %d\n",X[R[i]-1],Y[R[i]-1],i+1);
	//FOR(i,N) FORR(e,E[i]) if(i<e) _P("Segment %d %d %d %d\n",X[R[i]-1],Y[R[i]-1],X[R[e]-1],Y[R[e]-1]);
	FOR(i,N) _P("%d%c",R[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
