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

int N,CC;
int S[101010],T[101010],C[101010],did[101010];
vector<int> st[201010];

int pre[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>CC;
	FOR(i,N) {
		cin>>S[i]>>T[i]>>C[i];
		C[i]--;
		st[S[i]].push_back(i);
	}
	
	int num=0;
	FOR(i,CC) pre[i]=202020;
	FOR(i,101000) {
		
		FORR(e,st[i]) {
			if(pre[C[e]]<=S[e]) {
				pre[C[e]]=T[e];
				did[e]++;
			}
		}
		FORR(e,st[i]) if(did[e]==0) {
			FOR(j,CC) {
				if(pre[j]<S[e]) {
					pre[j]=202020;
					pre[C[e]]=T[e];
					break;
				}
			}
			if(j==CC) {
				pre[C[e]]=T[e];
				num++;
			}
		}
	}
	
	
	
	cout<<num<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
