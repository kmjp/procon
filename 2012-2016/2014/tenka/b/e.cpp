#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int L,N,M;
ll K[200010],num[200010],an[200010],ci[200010];
ll SS[200010];
vector<int> E[100010];
int pre[200010];

double score(int cur) {
	
	while(ci[cur]<E[cur].size()-1) {
		int o=E[cur][ci[cur]],n=E[cur][ci[cur]+1];
		if((SS[o]+K[cur]*an[cur])/(double)(num[o]+an[cur])<(SS[n]+K[cur]*an[cur])/(double)(num[n]+an[cur])) break;
		ci[cur]++;
	}
	int o=E[cur][ci[cur]];
	return (SS[o]+K[cur]*an[cur])/(double)(num[o]+an[cur]);
}

void solve() {
	int f,i,j,k,l,x,y;
	double dd;
	
	cin>>L>>N>>M;
	FOR(i,L) cin>>dd, K[i]=dd*1000+0.1;
	FOR(i,L) E[i].push_back(100000+i), pre[i]=100000+i;
	FOR(i,N) {
		cin>>x>>dd;
		x--;
		SS[i]=SS[pre[x]]+dd*1000+0.1;
		num[i]=1+num[pre[x]];
		while(E[x].size()>=2) {
			j=E[x][E[x].size()-1];
			k=E[x][E[x].size()-2];
			if((SS[i]-SS[k])*(num[j]-num[k])>(SS[j]-SS[k])*(num[i]-num[k])) break;
			E[x].pop_back();
		}
		E[x].push_back(i);
		pre[x]=i;
	}
	
	priority_queue<pair<double,int> > Q;
	vector<pair<int,int> > R;
	FOR(i,L) an[i]++, Q.push(make_pair(K[i]+K[i]-score(i),i));
	while(M--) {
		int cur=Q.top().second;
		Q.pop();
		if(E[cur][ci[cur]]>=100000) R.push_back(make_pair(0,cur+1));
		else R.push_back(make_pair(E[cur][ci[cur]]+1,cur+1));
		an[cur]++;
		Q.push(make_pair(K[cur]+K[cur]-score(cur),cur));
	}
	
	sort(R.begin(),R.end());
	FOR(i,R.size()) _P("%d %d\n",R[i].first,R[i].second);
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


