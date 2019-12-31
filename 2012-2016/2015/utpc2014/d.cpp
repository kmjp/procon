#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int X[1010],Y[1010],S[1010],T[1010];

int able[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) cin>>X[i]>>Y[i];
	cin>>N;
	FOR(i,N) {
		cin>>X[i+4]>>Y[i+4]>>S[i+4]>>T[i+4];
		if(i && X[i+4-1]==X[i+4] && Y[i+4-1]==Y[i+4]) {
			T[i+4-1]=T[i+4];
			i--;
			N--;
		}
	}
	FOR(y,N+5) FOR(x,y) able[x][y]=(S[y]-T[x])>=abs(Y[x]-Y[y])+abs(X[x]-X[y]);
	
	set<int> S,S2;
	if(M>=3) x+=1005*1005*2;
	S.insert(1005*(M>=2) + 1005*1005*2*(M>=3));
	FOR(i,N) {
		ITR(it,S) {
			int cur[3]={*it%1005,*it/1005%1005,*it/1005/1005};
			FOR(j,M) {
				if(able[cur[j]][i+4]) {
					int pre=cur[j];
					cur[j]=i+4;
					S2.insert(cur[0]+cur[1]*1005+cur[2]*1005*1005);
					cur[j]=pre;
				}
			}
		}
		swap(S,S2);
		S2.clear();
	}
	
	if(S.size()) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
