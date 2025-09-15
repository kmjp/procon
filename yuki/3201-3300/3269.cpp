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

int N,A[101010];
int L[101010],R[101010];
int num[201][101010];
int numP[201];
const int DI=500;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
	}
	//100‚Ü‚Å‚Í‹ð’¼
	for(i=1;i<=min(DI,N);i++) {
		unordered_set<int> M;
		int step=1;
		FOR(j,N) {
			M.insert(A[j]);
			if(M.size()>i) {
				M.clear();
				M.insert(A[j]);
				step++;
			}
		}
		cout<<step<<endl;
	}
	if(N<DI+1) return;
	
	int step=0;
	FOR(i,N) {
		R[step]=i;
		if(num[step][A[i]]==0&&numP[step]==DI+1) {
			step++;
			numP[step]++;
			num[step][A[i]]++;
			L[step]=i;
		}
		else {
			if(num[step][A[i]]==0) numP[step]++;
			num[step][A[i]]++;
		}
	}
	R[step]=N;
	cout<<step+1<<endl;
	
	for(i=DI+2;i<=N;i++) {
		FOR(j,step+1) {
			while(j&&L[j]<R[j-1]) {
				num[j][A[L[j]]]--;
				if(num[j][A[L[j]]]==0) numP[j]--;
				L[j]++;
			}
			if(L[j]>=R[j]) {
				for(k=R[j];k>L[j];k++) num[j][A[k]]=0;
				numP[j]=0;
				R[j]=L[j];
			}
			if(L[j]>=N) {
				step=j-1;
				break;
			}
			
			while(R[j]<N) {
				if(num[j][A[R[j]]]==0&&numP[j]==i) {
					break;
				}
				if(num[j][A[R[j]]]==0) numP[j]++;
				num[j][A[R[j]]]++;
				R[j]++;
			}
		}
		cout<<step+1<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
