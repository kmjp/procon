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


int N;
const ll mo=998244353;

ll dp[4030],S[4040];
int step[2515];
int stepS[2515][13];


ll hoge(int a,int b) {
	
	ll ret=0;
	int i,j;
	for(int num=1;num<=N;num++) {
		int s=0;
		while(1<<s<=num) s++;
		int tar=step[num];
		
		ZERO(dp);
		int mi=a+(num+1)/2*b+num/2*a;
		if(mi-a>=N) continue;
		
		if(num%2) {
			dp[a]=1;
		}
		else {
			dp[a+stepS[num][0]*b]=1;
		}
		
		for(i=1;i<s;i++) if(i!=tar) {
			int n=stepS[num][i];
			if(n==0) continue;
			//aˆÈã2aˆÈ‰º
			FOR(j,N+1) {
				S[j]=dp[j];
				if(j>=n) (S[j]+=S[j-n])%=mo;
				
				if(j>=n*a) {
					dp[j]=S[j-n*a];
					if(j>=n*(2*a+1)) {
						(dp[j]+=mo-S[j-n*(2*a+1)])%=mo;
					}
				}
				else {
					dp[j]=0;
				}
			}
		}
		
		int n=stepS[num][tar];
		if(tar==0) {
			
			FOR(i,N) if(i+(n-1)*b<N&&i+n*b>=N) {
				ret+=dp[i];
			}
		}
		else if(tar==s-1) {
			FOR(i,N) if(dp[i]) {
				int lef=N-i;
				if(lef<=a) {
					(ret+=dp[i]*(lef+1))%=mo;
				}
				else if(lef<=2*a) {
					for(int l=lef;l<=2*a;l++) {
						if(l==2*a) {
							(ret+=dp[i]*(lef-a))%=mo;
						}
						else {
							(ret+=dp[i]*(lef+1-a))%=mo;
						}
						
					}
					
				}
			}
		}
		else {
			FOR(i,N) if(dp[i]) {
				for(int l=a;l<=2*a;l++) {
					if(i+(n-1)*l<N&&i+n*l>=N) {
						int lef=N-(i+(n-1)*l);
						int b2=2*a-l;
						int a2=(l-b2)/2;
						if(l==a*2) {
							(ret+=dp[i]*min(lef+1,a+1))%=mo;
						}
						else if(lef<=a2) {
							(ret+=dp[i]*(lef+1))%=mo;
						}
						else if(lef<=a) {
							(ret+=dp[i])%=mo;
						}
						else {
							(ret+=dp[i]*(lef+1-a))%=mo;
						}
						
					}
				}
			}
			
		}
		ret%=mo;
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=2510;i++) {
		FOR(j,13) stepS[i][j]=stepS[i-1][j];
		x=i;
		while(x%2==0) x/=2, step[i]++;
		stepS[i][step[i]]++;
	}
	
	cin>>N;
	N++;
	ll ret=1;
	int step=0;
	for(i=1;i<N;i++) {
		k=0;
		while(1<<k<i) k++;
		y=1<<k;
		if(i==y) continue;
		int a=i;
		int b=y-i;
		
		ret+=hoge(a,b);
	}
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
