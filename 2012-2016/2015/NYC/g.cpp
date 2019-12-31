#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll T,X[101000],Y[101000];
char M[101000];
ll ST[101000];
map<int,int> XM,YM;
map<int,int> HL[101000],VL[1010000];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>M[i];
		ST[i]=1LL<<60;
		XM[X[i]]=YM[Y[i]]=0;
	}
	x=0; ITR(it,XM) it->second=x++;
	x=0; ITR(it,YM) it->second=x++;
	FOR(i,N) {
		HL[YM[Y[i]]][X[i]]=i;
		VL[XM[X[i]]][Y[i]]=i;
	}
	
	ST[0]=0;
	priority_queue<pair<ll,int> > Q;
	Q.push(make_pair(0,0));
	while(Q.size()) {
		ll ct=-Q.top().first;
		int k=Q.top().second;
		Q.pop();
		if(ct!=ST[k]) continue;
		HL[YM[Y[k]]].erase(X[k]);
		VL[XM[X[k]]].erase(Y[k]);
		
		map<int,int>::iterator it;
		if(M[k]=='U') {
			for(it=VL[XM[X[k]]].lower_bound(Y[k]); it!=VL[XM[X[k]]].end();it++) {
				ll nt=ST[k]+abs(Y[it->second]-Y[k]);
				if(nt<ST[it->second]) {
					ST[it->second]=nt;
					Q.push(make_pair(-nt,it->second));
				}
				if(M[it->second]==M[k]) break;
			}
		}
		if(M[k]=='D') {
			for(it=VL[XM[X[k]]].lower_bound(Y[k]);it!=VL[XM[X[k]]].begin();) {
				it--;
				ll nt=ST[k]+abs(Y[it->second]-Y[k]);
				if(nt<ST[it->second]) {
					ST[it->second]=nt;
					Q.push(make_pair(-nt,it->second));
				}
				if(M[it->second]==M[k]) break;
			}
		}
		if(M[k]=='L') {
			for(it=HL[YM[Y[k]]].lower_bound(X[k]);it!=HL[YM[Y[k]]].begin();) {
				it--;
				ll nt=ST[k]+abs(X[it->second]-X[k]);
				if(nt<ST[it->second]) {
					ST[it->second]=nt;
					Q.push(make_pair(-nt,it->second));
				}
				if(M[it->second]==M[k]) break;
			}
		}
		if(M[k]=='R') {
			for(it=HL[YM[Y[k]]].lower_bound(X[k]); it!=HL[YM[Y[k]]].end();it++) {
				ll nt=ST[k]+abs(X[it->second]-X[k]);
				if(nt<ST[it->second]) {
					ST[it->second]=nt;
					Q.push(make_pair(-nt,it->second));
				}
				if(M[it->second]==M[k]) break;
			}
		}
		
	}
	
	
	FOR(i,N) {
		ll xx=X[i],yy=Y[i];
		if(M[i]=='U') yy+=max(0LL,T-ST[i]);
		if(M[i]=='D') yy-=max(0LL,T-ST[i]);
		if(M[i]=='L') xx-=max(0LL,T-ST[i]);
		if(M[i]=='R') xx+=max(0LL,T-ST[i]);
		_P("%lld %lld\n",xx,yy);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
