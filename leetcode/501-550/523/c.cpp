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

int state[1010101];

class BusBooking {
public:
int s1,s2;
    BusBooking(int n) {
		int i;
		FOR(i,n*4+10) state[i]=0;
		s1=s2=0;
    }
    
    void toggle(string seat) {
		
		string P=seat.substr(0,1);
		int x=atoi(seat.substr(1).c_str());
		int id=P[0]-'A'+x*4;
		
		if(state[id]) {
			s1-=state[id];
			s2--;
			state[id]=0;
		}
		else {
			int cost=1;
			if(P=="A"&&state[id+1]||P=="D"&&state[id-1]) cost=3;
			s1+=cost;
			s2++;
			state[id]=cost;
		}
		
    }
    
    int getTotalTime() {
		return s1;
        
    }
    
    int getMinTime() {
		return s2;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
 
 
 
 