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
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
		int M1=(arriveAlice[0]-'0')*10+(arriveAlice[1]-'0')-1;
		int D1=(arriveAlice[3]-'0')*10+(arriveAlice[4]-'0')-1;
		int M2=(leaveAlice[0]-'0')*10+(leaveAlice[1]-'0')-1;
		int D2=(leaveAlice[3]-'0')*10+(leaveAlice[4]-'0')-1;
		int M3=(arriveBob[0]-'0')*10+(arriveBob[1]-'0')-1;
		int D3=(arriveBob[3]-'0')*10+(arriveBob[4]-'0')-1;
		int M4=(leaveBob[0]-'0')*10+(leaveBob[1]-'0')-1;
		int D4=(leaveBob[3]-'0')*10+(leaveBob[4]-'0')-1;
        
        vector<int> D={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int m,d;
        int ret=0;
        FOR(m,12) FOR(d,D[m]) {
			if(M1>m||M2<m) continue;
			if(M1==m&&d<D1) continue;
			if(M2==m&&d>D2) continue;
			if(M3>m||M4<m) continue;
			if(M3==m&&d<D3) continue;
			if(M4==m&&d>D4) continue;
			ret++;
		}
        return ret;
    }
};
