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

int N;
string S;
int O[101010],C[101010],H[101010];
int Q;
pair<pair<int,int>,int> QQ[101010];

int ok[101010];
int pa[101010];

int dif[2][1001010][20];
int heko[2][1001010][20];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) {
		O[i+1]=O[i]+(S[i]=='(');
		C[i+1]=C[i]+(S[i]==')');
		H[i+1]=H[i]+(S[i]=='?');
		if(S[i]=='(') dif[0][i+1][0]=dif[1][i+1][0]=1;
		if(S[i]==')') dif[0][i+1][0]=heko[0][i+1][0]=-1, dif[1][i+1][0]=heko[1][i+1][0]=-1;
		if(S[i]=='?') {
			dif[0][i+1][0]=1;
			dif[1][i+1][0]=heko[1][i+1][0]=-1;
		}
	}
	
	FOR(x,17) {
		FOR(i,N+2) {
			FOR(j,2) {
				dif[j][i][x+1]=dif[j][i][x]+dif[j][i+(1<<x)][x];
				heko[j][i][x+1]=min(heko[j][i][x],dif[j][i][x]+heko[j][i+(1<<x)][x]);
			}
		}
	}
	
	cin>>Q;
	FOR(i,Q) {
		int L,R;
		cin>>L>>R;
		
		if((R-L)%2==0) {
			_P("No\n");
			continue;
		}
		
		int dd=(O[R]-O[L-1])-(C[R]-C[L-1]);
		int fr=H[R]-H[L-1];
		
		if(abs(dd)>fr) {
			_P("No\n");
			continue;
		}
		
		int op=(fr-dd)/2;
		int cl=(fr+dd)/2;
		
		int T=L-1;
		for(x=17;x>=0;x--) if(T+(1<<x)<=R) {
			y=T+(1<<x);
			int dd=H[y]-H[L-1];
			if(dd<=op) T+=1<<x;
		}
		
		int d=0,h=0;
		for(x=17;x>=0;x--) {
			if(T+1>=L+(1<<x)) {
				h=min(h,d+heko[0][L][x]);
				d+=dif[0][L][x];
				L+=1<<x;
			}
		}
		for(x=17;x>=0;x--) {
			if(R+1>=L+(1<<x)) {
				h=min(h,d+heko[1][L][x]);
				d+=dif[1][L][x];
				L+=1<<x;
			}
		}
		if(h==0) _P("Yes\n");
		else _P("No\n");
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
