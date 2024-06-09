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
    int findWinningPlayer(vector<int>& skills, int k) {
		queue<int> Q;
		int i;
		FOR(i,skills.size()) Q.push({i});
		Q.pop();
		int cur=0;
		int win=0;
		while(1) {
			if(skills[cur]<skills[Q.front()]) {
				cur=Q.front();
				win=1;
				Q.push(cur);
				Q.pop();
			}
			else {
				win++;
				Q.push(Q.front());
				Q.pop();
			}
			if(win>=k || win>=skills.size()) return cur;
		}
		
        return 1;
    }
};
