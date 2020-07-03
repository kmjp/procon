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


int N,K;
string S[101];
set<pair<string,vector<int>>> memo;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,100) {
		S[i]=to_string(i);
		FORR(c,S[i]) c=(9-(c-'0'))+'0';
	}
	
	cin>>N>>K;
	vector<int> L(100);
	int ML=0;
	FOR(i,N) {
		cin>>x;
		L[x]++;
		ML+=S[x].size();
	}
	
	
	priority_queue<tuple<string,vector<int>,int>,vector<tuple<string,vector<int>,int>>,greater<tuple<string,vector<int>,int>>> PQ;
	PQ.push({"",L,-1});
	while(K) {
		string cur=get<0>(PQ.top());
		vector<int> V=get<1>(PQ.top());
		int pre=get<2>(PQ.top());
		PQ.pop();
		
		if(cur.size()==ML) {
			FORR(c,cur) c=(9-(c-'0'))+'0';
			cout<<cur<<endl;
			K--;
			continue;
		}
		
		for(i=10;i<100;i++) {
			if(i%11==0 && V[i/11]) {
				string cur2=cur;
				if(i==pre*11) continue;
				
				for(x=1;x<=V[i]*2+V[i/11];x++) {
					int p1=V[i],p11=V[i/11];
					cur2+=S[i/11];
					r=min(V[i],x/2);
					V[i]-=r;
					V[i/11]-=(x-r*2);
					if(memo.count({cur2,V})==0) {
						PQ.push({cur2,V,i/11});
						memo.insert({cur2,V});
					}
					V[i]=p1;
					V[i/11]=p11;
				}
			}
			else if(V[i]) {
				V[i]--;
				if(memo.count({cur+S[i],V})==0) {
					PQ.push({cur+S[i],V,i});
					memo.insert({cur+S[i],V});
				}
				V[i]++;
			}
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
