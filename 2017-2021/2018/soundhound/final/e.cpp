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

const int DI=300;
int N,M,Q;
string S[21][700];
ll phash[21][700];

ll p10[201010];
ll mo=1000000007;


void update(int cur,int id) {
	ll ret=0;
	for(int i=(int)S[cur][id].size()-1;i>=0;i--) ret=(ret*1000000+S[cur][id][i])%mo;
	phash[cur][id]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,200010) p10[i+1]=p10[i]*1000000%mo;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>s;
		FOR(x,N) S[i][x/DI].push_back(s[x]-'a'+1);
		FOR(x,N/DI+2) update(i,x);
	}
	cin>>Q;
	while(Q--) {
		int T,X,Y,L,R;
		cin>>T>>X>>Y>>L>>R;
		X--,Y--,L--;
		if(T==1) {
			if(L%DI) {
				while(L%DI && L<R) swap(S[X][L/DI][L%DI],S[Y][L/DI][L%DI]), L++;
				update(X,(L-1)/DI);
				update(Y,(L-1)/DI);
			}
			if(R%DI) {
				while(R%DI && L<R) R--, swap(S[X][R/DI][R%DI],S[Y][R/DI][R%DI]);
				update(X,R/DI);
				update(Y,R/DI);
			}
			while(L<R) {
				swap(S[X][L/DI],S[Y][L/DI]);
				swap(phash[X][L/DI],phash[Y][L/DI]);
				L+=DI;
			}
		}
		else {
			ll ret=0;
			int len=0;
			while(L%DI && L<R) (ret+=p10[len]*S[X][L/DI][L%DI])%=mo, len++, L++;
			while(L+DI<=R) (ret+=p10[len]*phash[X][L/DI])%=mo, len+=DI, L+=DI;
			while(L<R) (ret+=p10[len]*S[X][L/DI][L%DI])%=mo, len++, L++;
			cout<<ret<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
