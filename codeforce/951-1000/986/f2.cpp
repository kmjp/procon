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

int T,N,M;
int A[202020];
bitset<10240> B[18],cur,sum,pre,nex;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		FOR(i,18) B[i].reset();
		cur.reset();
		sum.reset();
		pre.reset();
		
		
		cin>>N>>M;
		vector<int> V;
		pre[0]=sum[0]=1;
		FOR(i,N) {
			nex.reset();
			cin>>x;
			
			if(x==0) {
				nex=sum;
				V.clear();
				cur=sum;
			}
			else if(x==1) {
				nex=pre|(pre<<1)|cur;
			}
			else {
				
				nex=(pre<<x)|cur;
				FOR(j,V.size()) {
					V[j]*=x;
					nex|=B[j]<<V[j];
				}
				while(V.size()&&V.back()>M) V.pop_back();
				for(j=(int)V.size()-1;j>=0;j--) B[j+1]=B[j];
				B[0]=pre;
				V.insert(V.begin(),x);
				while(V.size()&&V.back()>M) V.pop_back();
			}
			
			sum|=nex;
			pre=nex;
		}
		if(pre[M]) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
