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

int N,K;
int C[202000];
pair<int,int> P[202000];
int Q,D[202000];
int L[202000],R[202000];
ll tot=0;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>C[i];
		P[i]=make_pair(C[i],i);
	}
	sort(P,P+N);
	multiset<int> sm,la;
	FOR(i,N) {
		L[P[i].second]=(i==0)?-1:P[i-1].second;
		R[P[i].second]=(i==N-1)?N:P[i+1].second;
		if(i!=N-1) la.insert(P[i+1].first-P[i].first);
	}
	
	while(la.size()>=K) tot+=*la.begin(),sm.insert(*la.begin()), la.erase(la.begin());
	cout<<tot<<endl;
	cin>>Q;
	FOR(i,Q) {
		multiset<int>::iterator mit;
		cin>>D[i],D[i]--;
		if(L[D[i]]==-1) {
			int dif=C[R[D[i]]]-C[D[i]];
			mit=la.find(dif);
			if(mit!=la.end()) la.erase(mit);
			else tot-=dif, sm.erase(sm.lower_bound(dif));
			L[R[D[i]]]=-1;
		}
		else if(R[D[i]]==N) {
			int dif=C[D[i]]-C[L[D[i]]];
			mit=la.find(dif);
			if(mit!=la.end()) la.erase(mit);
			else tot-=dif, sm.erase(sm.lower_bound(dif));
			R[L[D[i]]]=N;
		}
		else {
			int dif1=C[R[D[i]]]-C[D[i]];
			int dif2=C[D[i]]-C[L[D[i]]];
			int dif3=C[R[D[i]]]-C[L[D[i]]];
			mit=la.find(dif1);
			if(mit!=la.end()) la.erase(mit);
			else tot-=dif1, sm.erase(sm.lower_bound(dif1));
			mit=la.find(dif2);
			if(mit!=la.end()) la.erase(mit);
			else tot-=dif2, sm.erase(sm.lower_bound(dif2));
			
			la.insert(dif3);
			while(la.size()>=K) tot+=*la.begin(),sm.insert(*la.begin()), la.erase(la.begin());
			L[R[D[i]]]=L[D[i]];
			R[L[D[i]]]=R[D[i]];
		}
		while(la.size()<K-1) {
			multiset<int>::iterator mit=sm.end();
			mit--;
			tot-=*mit,la.insert(*mit), sm.erase(mit);
		}
		cout<<tot<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
