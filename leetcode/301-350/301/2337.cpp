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


class Solution {
public:
    bool canChange(string start, string target) {
		vector<int> Ls,Rs,Lt,Rt;
		string A,B;
        int i;
        FOR(i,start.size()) {
			if(start[i]=='L') Ls.push_back(i),A+="L";
			if(start[i]=='R') Rs.push_back(i),A+="R";
		}
        FOR(i,start.size()) {
			if(target[i]=='L') Lt.push_back(i),B+="L";
			if(target[i]=='R') Rt.push_back(i),B+="R";
		}
		if(A!=B) return 0;
		FOR(i,Ls.size()) if(Ls[i]<Lt[i]) return 0;
		FOR(i,Rs.size()) if(Rs[i]>Rt[i]) return 0;
		return 1;
        
    }
};
