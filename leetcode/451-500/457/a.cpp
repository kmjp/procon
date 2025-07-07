#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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


class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
		map<string,multiset<string>> M;
		int i;
		FOR(i,isActive.size()) if(isActive[i]) {
			int ok=1;
			FORR(c,code[i]) {
				int tmp=0;
				if(c>='A'&&c<='Z') tmp=1;
				if(c>='a'&&c<='z') tmp=1;
				if(c>='0'&&c<='9') tmp=1;
				if(c=='_') tmp=1;
				ok&=tmp;
			}
			if(code[i].empty()) ok=0;
			if(ok) M[businessLine[i]].insert(code[i]);
		}
		
		vector<string> V;
		FORR(a,M["electronics"]) V.push_back(a);
		FORR(a,M["grocery"]) V.push_back(a);
		FORR(a,M["pharmacy"]) V.push_back(a);
		FORR(a,M["restaurant"]) V.push_back(a);
        return V;
    }
};
