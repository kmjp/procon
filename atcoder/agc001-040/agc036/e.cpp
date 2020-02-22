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

string S,T;
int C[3];
int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	FORR(c,S) {
		if(T.empty() || c!=T.back()) {
			T+=c;
			C[c-'A']++;
		}
	}
	pair<int,char> P[3];
	P[0]={C[0],'A'};
	P[1]={C[1],'B'};
	P[2]={C[2],'C'};
	sort(P,P+3);
	FOR(i,3) C[i]=P[i].first;
	FORR(c,T) {
		FOR(i,3) if(c==P[i].second) {
			c=i;
			break;
		}
	}
	vector<string> V;
	int cur=0;
	while(cur<T.size()) {
		if(T[cur]==2) {
			if(C[2]>C[1]) {
				C[2]--;
			}
			else {
				V.push_back(T.substr(cur,1));
			}
			cur++;
		}
		else if(T[cur]==0) {
			V.push_back(T.substr(cur,1));
			cur++;
			while(cur+2<=T.size() && T[cur]==2 && T[cur+1]==0) {
				V.back().push_back(2);
				V.back().push_back(0);
				cur+=2;
			}
		}
		else if(T[cur]==1) {
			V.push_back(T.substr(cur,1));
			cur++;
			while(cur+2<=T.size() && T[cur]==2 && T[cur+1]==1) {
				V.back().push_back(2);
				V.back().push_back(1);
				cur+=2;
			}
		}
	}
	FORR(v,V) {
		while(v[0]==0 && C[2]>C[1] && v.size()>=3) {
			v.pop_back();
			v.pop_back();
			C[0]--;
			C[2]--;
		}
	}
	assert(C[1]==C[2]);
	S.clear();
	FORR(v,V) S+=v;
	T.clear();
	cur=0;
	while(cur<S.size()) {
		if(C[1]>C[0] && cur+3<=S.size() && ((S[cur]==1&&S[cur+1]==2&&S[cur+2]==1)||(S[cur]==2&&S[cur+1]==1&&S[cur+2]==2))) {
			cur+=2;
			C[1]--;
			C[2]--;
			continue;
		}
		if(C[1]>C[0] && cur+2==S.size() && ((S[cur]==1&&S[cur+1]==2)||(S[cur]==2&&S[cur+1]==1))) {
			cur+=2;
			C[1]--;
			C[2]--;
			continue;
		}
		T.push_back(S[cur]);
		cur++;
	}
	//assert(C[1]==C[0]);
	
	FORR(c,T) cout<<P[c].second;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
