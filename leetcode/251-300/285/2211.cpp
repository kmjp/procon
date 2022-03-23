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
    int countCollisions(string directions) {
		int cnt=0;
		string S;
		FORR(c,directions) {
			if(c=='L') {
				if(S.back()=='S') {
					cnt++;
				}
				else {
					if(S.size()&&S.back()=='R') {
						while(S.size()&&S.back()=='R') {
							cnt+=1;
							S.pop_back();
						}
						cnt++;
						S+='S';
					}
				}
			}
			else if(c=='S') {
				while(S.size()&&S.back()=='R') {
					cnt++;
					S.pop_back();
				}
				S+=c;
			}
			else {
				S+=c;
			}
		}
        return cnt;
    }
};