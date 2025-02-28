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

int T;
int N;
int A[505050];
int re[505050];
int L[505050];
int R[505050];
int LP[505050];
int RP[505050];

ll sum[505050];
vector<int> Ls[505050],Rs[505050];
ll dif[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		set<int> S={0,N+1};
		FOR(i,N) {
			S.insert(i+1);
			cin>>A[i+1];
			re[A[i+1]]=i+1;
		}
		A[0]=A[N+1]=N+1;
		FOR(i,N+3) dif[i]=0;
		
		ll TS=0;
		for(i=N;i>=1;i--) {
			x=re[i];
			auto it=S.find(x);
			sum[x]=0;
			Ls[x].clear();
			Rs[x].clear();
			
			
			vector<int> RL,LR;
			if(*prev(it)==0||A[*prev(it)]<i) {
				LP[x]=0;
				L[x]=x;
			}
			else {
				LP[x]=*prev(it);
				L[x]=L[LP[x]];
				swap(Ls[x],Ls[LP[x]]);
				swap(RL,Rs[LP[x]]);
			}
			if(*next(it)==N+1||A[*next(it)]<i) {
				RP[x]=N+1;
				R[x]=x;
			}
			else {
				RP[x]=*next(it);
				R[x]=R[RP[x]];
				swap(Rs[x],Rs[RP[x]]);
				swap(LR,Ls[RP[x]]);
			}
			
			dif[x+1]-=1LL*(x-L[x]+1)*A[x];
			dif[R[x]+1]+=1LL*(x-L[x]+1)*A[x];
			dif[L[x]]-=1LL*(R[x]-x+1)*A[x];
			dif[x]+=1LL*(R[x]-x+1)*A[x];
			
			sum[x]=-1LL*i*(x+1-L[x])*(R[x]+1-x);
			TS+=1LL*i*(x+1-L[x])*(R[x]+1-x);
			
			int CL=L[x];
			int CR=R[x];
			while(RL.size()||LR.size()) {
				if(RL.empty()) {
					pat1:
					y=LR.back();
					sum[x]+=1LL*A[y]*(x-CL)*(CR-y+1);
					CR=y-1;
					LR.pop_back();
				}
				else if(LR.empty()) {
					pat2:
					y=RL.back();
					sum[x]+=1LL*A[y]*(y-CL+1)*(CR-x);
					CL=y+1;
					RL.pop_back();
				}
				else if(A[LR.back()]<A[RL.back()]) {
					goto pat1;
				}
				else {
					goto pat2;
				}
			}
			
			if(LP[x]!=0) S.erase(LP[x]);
			if(RP[x]!=N+1) S.erase(RP[x]);
			
			
			Ls[x].push_back(x);
			Rs[x].push_back(x);
		}
		
		
		FOR(i,N) {
			dif[i+1]+=dif[i];
			cout<<TS+sum[i+1]+dif[i+1]<<" ";
		}
		cout<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
