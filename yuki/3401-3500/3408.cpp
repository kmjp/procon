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

int C[10];
int L;
ll N;
ll ret;
ll p10[21];

int S[10][7]={
	{1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1},
};

void hoge() {
	
	int seg[7]={};
	int i,j,x,sum=0;
	FOR(i,10) {
		sum+=C[i];
		FOR(j,7) seg[j]+=S[i][j]*C[i];
	}
	if((seg[2]+seg[4])%2) return;
	int tar=(seg[2]+seg[4])/2;
	if(seg[3]>tar) {
		int mi=min(seg[3]-tar,C[9]);
		seg[3]-=mi;
	}
	if(seg[6]<tar) {
		int mi=min(tar-seg[6],C[0]);
		seg[6]+=mi;
		seg[0]-=mi;
		seg[1]-=mi;
		seg[5]-=mi;
	}
	if(seg[4]<tar) {
		int mi=min(tar-seg[4],C[1]);
		seg[4]+=mi;
		seg[5]+=mi;
		seg[1]-=mi;
		seg[2]-=mi;
	}
	if(seg[0]>tar) {
		int mi=min(seg[0]-tar,C[6]);
		seg[0]-=mi;
	}
	if(seg[5]<tar) {
		int mi=min(tar-seg[5],C[7]);
		seg[5]+=mi;
	}
	FOR(i,7) if(seg[0]!=seg[i]) return;
	
	ll v=0;
	x=0;
	for(i=1;i<10;i++) if(C[i]&&x==0) {
		v=x=i;
		break;
	}
	FOR(i,10) {
		FOR(j,C[i]-(i==x)) v=v*10+i;
	}
	
	string NS=to_string(N);
	string V=to_string(v);
	FOR(i,sum) {
		if(atoll(V.c_str())>=N) {
			ret=min(ret,atoll(V.c_str()));
			break;
		}
		for(j=i+1;j<sum;j++) {
			if(V[j]>NS[i]) {
				string V2=V;
				swap(V2[j],V2[i]);
				sort(V2.begin()+i+1,V2.end());
				ll nv=atoll(V2.c_str());
				if(nv>=N) ret=min(ret,nv);
				break;
			}
		}
		for(j=i;j<sum;j++) {
			if(V[j]==NS[i]) {
				swap(V[j],V[i]);
				sort(V.begin()+i+1,V.end());
				break;
			}
		}
		if(j>=sum) break;
		
	}
	
}
	
	


void dfs(int cur,int sum) {
	
	
	
	if(sum>=20||cur==10) return;
	
	dfs(cur+1,sum);
	
	C[cur]++;
	sum++;
	
	if(sum==L||sum==L+1) hoge();
	
	dfs(cur,sum);
	sum--;
	C[cur]--;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,20) p10[i+1]=p10[i]*10;
	
	cin>>N;
	string S=to_string(N);
	L=S.size();
	ret=1LL<<62;
	dfs(0,0);
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
