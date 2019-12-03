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
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
		int L=bottomLeft[0],D=bottomLeft[1];
		int R=topRight[0],U=topRight[1];
		
		vector<int> Xs,Ys;
		int x,y,i;
		int pre=L;
		while(pre<=R) {
			if(sea.hasShips({R,U},{pre,D})==0) break;
			int tar=pre-1;
			for(i=10;i>=0;i--) if(tar+(1<<i)<=R) {
				if(sea.hasShips({tar+(1<<i),U},{pre,D})==0) tar+=(1<<i);
			}
			Xs.push_back(tar+1);
			pre=tar+2;
		}
		pre=D;
		while(pre<=U) {
			if(sea.hasShips({R,U},{L,pre})==0) break;
			int tar=pre-1;
			for(i=10;i>=0;i--) if(tar+(1<<i)<=U) {
				if(sea.hasShips({R,tar+(1<<i)},{L,pre})==0) tar+=(1<<i);
			}
			Ys.push_back(tar+1);
			pre=tar+2;
		}
		
		int num=0;
		FORR(x,Xs) FORR(y,Ys) num+=sea.hasShips({x,y},{x,y});
		return num;
		
		
        
    }
};
