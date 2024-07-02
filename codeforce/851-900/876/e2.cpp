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
int A[303];
bitset<90200> BS[301];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	BS[0][0]=1;
	int sum=0;
	FOR(i,N) {
		cin>>A[i];
		BS[i+1]=BS[i]|(BS[i]<<A[i]);
		sum+=A[i];
	}
	
	set<int> S[2];
	if(sum%2==0&&BS[N][sum/2]) {
		cout<<"Second"<<endl;
		sum/=2;
		int cur=N;
		while(cur>0) {
			cur--;
			if(sum>=A[cur]&&BS[cur][sum-A[cur]]) {
				S[0].insert(cur);
				sum-=A[cur];
			}
			else {
				S[1].insert(cur);
			}
		}
		while(1) {
			cin>>j;
			if(j==0) break;
			j--;
			int t=S[0].count(j);
			FORR(c,S[t]) {
				if(A[c]) x=c;
			}
			cout<<(x+1)<<endl;
			k=min(A[x],A[j]);
			A[x]-=k;
			A[j]-=k;
		}
	}
	else {
		cout<<"First"<<endl;
		while(1) {
			FOR(i,N) if(A[i]) break;
			cout<<(i+1)<<endl;
			cin>>j;
			if(j==0) break;
			j--;
			k=min(A[i],A[j]);
			A[i]-=k;
			A[j]-=k;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
