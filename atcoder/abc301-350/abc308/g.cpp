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

int Q;
multiset<int> S;
multiset<int> cand;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==3) {
			cout<<*cand.begin()<<endl;
		}
		else {
			cin>>x;
			if(i==1) {
				
				if(S.size()) {
					auto it=S.lower_bound(x);
					if(it==S.begin()) {
						cand.insert(*it^x);
					}
					else {
						auto it2=prev(it);
						if(it==S.end()) {
							cand.insert(*it2^x);
						}
						else {
							cand.erase(cand.find(*it^*it2));
							cand.insert(*it^x);
							cand.insert(*it2^x);
						}
					}
				}
				S.insert(x);
				
				
			}
			else {
				auto it=S.find(x);
				if(S.size()>1) {
					if(it==S.begin()) {
						cand.erase(cand.find(x^*next(it)));
					}
					else if(next(it)==S.end()) {
						cand.erase(cand.find(x^*prev(it)));
					}
					else {
						cand.erase(cand.find(x^*next(it)));
						cand.erase(cand.find(x^*prev(it)));
						cand.insert(*next(it)^*prev(it));
					}
				}
				S.erase(it);
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
