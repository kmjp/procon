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
ll W[101010],T[101010],X[101010];
ll add[3][3710000];

int day[101010];
ll num[4000000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>W[i]>>T[i]>>X[i];
	
	ll cur[3]={};
	ll tot=0;
	int did=0;
	MINUS(day);
	for(i=0;i<=3700000;i++) {
		tot += cur[0] + cur[1]*i + cur[2]*i*i;
		num[i]=tot;
		
		while(did<N && tot>=W[did]) {
			day[did]=i;
			if(T[did]==0) {
				cur[0]++;
				add[0][i+X[did]]--;
			}
			else if(T[did]==1) {
				cur[0]-=i;
				add[0][i+X[did]]+=i;
				cur[1]++;
				add[1][i+X[did]]--;
			}
			else if(T[did]==2) {
				cur[0]+=1LL*i*i;
				add[0][i+X[did]]-=1LL*i*i;
				cur[1]-=2LL*i;
				add[1][i+X[did]]+=2LL*i;
				cur[2]++;
				add[2][i+X[did]]--;
			}
			did++;
		}
		if(i==0) cur[0]++;
		cur[0]+=add[0][i];
		cur[1]+=add[1][i];
		cur[2]+=add[2][i];
	}
	
	FOR(i,N) {
		if(day[i]<0 || day[i]>3652425) cout<<"Many years later"<<endl;
		else cout<<day[i]<<endl;
	}
	FOR(i,Q) {
		cin>>x;
		cout<<num[x]<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
