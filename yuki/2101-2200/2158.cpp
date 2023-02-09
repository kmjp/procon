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

int N,K;
int P[55],S[55],T[55];
double dp[3][6][6][6][6][6][6];
int V[6];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>P[i]>>S[i]>>T[i];
	for(i=N;i<6;i++) P[i]=5;
	
	int sum=0;
	FOR(i,6) sum+=T[i];
	if(sum>60) {
		cout<<-1<<endl;
		return;
	}
	sum=0;
	FOR(i,6) sum+=S[i];
	if(sum<=60) {
		cout<<"1 1 1"<<endl;
		return;
	}
	
	for(V[0]=P[0];V[0]>=K;V[0]--)
	for(V[1]=P[1];V[1]>=K;V[1]--)
	for(V[2]=P[2];V[2]>=K;V[2]--)
	for(V[3]=P[3];V[3]>=K;V[3]--)
	for(V[4]=P[4];V[4]>=K;V[4]--)
	for(V[5]=P[5];V[5]>=K;V[5]--) {
		int mask;
		dp[0][V[0]][V[1]][V[2]][V[3]][V[4]][V[5]]=1e9;
		dp[1][V[0]][V[1]][V[2]][V[3]][V[4]][V[5]]=-1e9;
		dp[2][V[0]][V[1]][V[2]][V[3]][V[4]][V[5]]=0;
		int V2[6];
		
		FOR(mask,64) {
			double p=1;
			int sum=0;
			FOR(i,6) {
				if(mask&(1<<i)) { //new
					p=p*(P[i]-V[i])/(P[i]-K);
					sum+=S[i];
					V2[i]=V[i]+1;
				}
				else {
					p=p*(V[i]-K)/(P[i]-K);
					sum+=T[i];
					V2[i]=V[i];
				}
			}
			if(p==0) continue;
			if(sum<=60) {
				dp[0][V[0]][V[1]][V[2]][V[3]][V[4]][V[5]]=1;
				chmax(dp[1][V[0]][V[1]][V[2]][V[3]][V[4]][V[5]],1.0);
				dp[2][V[0]][V[1]][V[2]][V[3]][V[4]][V[5]]+=p;
			}
			else {
				chmin(dp[0][V[0]][V[1]][V[2]][V[3]][V[4]][V[5]],dp[0][V2[0]][V2[1]][V2[2]][V2[3]][V2[4]][V2[5]]+1);
				chmax(dp[1][V[0]][V[1]][V[2]][V[3]][V[4]][V[5]],dp[1][V2[0]][V2[1]][V2[2]][V2[3]][V2[4]][V2[5]]+1);
				dp[2][V[0]][V[1]][V[2]][V[3]][V[4]][V[5]]+=p*(dp[2][V2[0]][V2[1]][V2[2]][V2[3]][V2[4]][V2[5]]+1);
			}
		}
	}
	
	_P("%.12lf %.12lf %.12lf\n",dp[0][K][K][K][K][K][K]+K,dp[1][K][K][K][K][K][K]+K,dp[2][K][K][K][K][K][K]+K);
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
