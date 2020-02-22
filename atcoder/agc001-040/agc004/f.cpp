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
set<int> E[101010];
ll sum;
int D[101010],RD,SP[101010];
int U,V;


int dfs(int cur,int pre,int type) {
	int ret=type+SP[cur];
	FORR(r,E[cur]) if(r!=pre) ret += dfs(r,cur,-type);
	sum += abs(ret);
	return ret;
}
void dfs2(int cur,int pre,int d) {
	D[cur]=d;
	FORR(r,E[cur]) if(r!=pre) {
		
		if(D[r]>=0) {
			if(RD==0) U=cur, V=r, RD=d+1-D[r];
		}
		else dfs2(r,cur,d+1);
	}
}

ll test(int v) {
	sum=abs(v);
	SP[U]=v;
	SP[V]=-v;
	dfs(U,-1,1);
	return sum;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
	}
	
	if(M==N-1) {
		x = dfs(0,-1,1);
		if(x!=0) sum=-1;
	}
	else {
		MINUS(D);
		dfs2(0,-1,0);
		E[U].erase(V);
		E[V].erase(U);
		
		if(RD%2==1) {
			x = dfs(U,-1,1);
			if(abs(x)%2==1) return _P("-1\n");
			sum = abs(x)/2;
			SP[U]-=x/2;
			SP[V]-=x/2;
			dfs(U,-1,1);
		}
		else {
			x = dfs(U,-1,1);
			ll tsum=sum;
			if(x) return _P("-1\n");
			
			ll L=-101010,R=101010;
			while(R-L>5) {
				int M1=(2*L+R)/3;
				int M2=(L+R*2)/3;
				ll sum1=test(M1);
				ll sum2=test(M2);
				if(sum1<sum2) R=M2;
				if(sum1>sum2) L=M1;
				if(sum1==sum2) L=M1,R=M2;
			}
			for(x=L;x<=R;x++) tsum=min(tsum,test(x));
			sum=tsum;
		}
		
	}
	cout<<sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
