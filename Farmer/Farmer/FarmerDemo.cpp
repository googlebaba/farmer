#include "farmer.h"
using namespace std;
int main()
{
	slove();
	return 0;
}

inline bool farmer(int status)
{
	return ((status&0x08)!=0);
}

inline bool wolf(int status)
{
	return ((status&0x04)!=0);
}

inline bool cabbage(int status)
{
	return ((status&0x02)!=0);
}

inline bool goat(int status)
{
	return ((status&0x01)!=0);
}

bool safe(int status)
{
	if((goat(status)==cabbage(status))&&
		(goat(status)!=farmer(status)))
		return false;
	else if((goat(status)==wolf(status))&&
		(goat(status)!=farmer(status)))
		return false;
	else 
		return true;
}

void slove()
{
	int END = 15;
	int i,location,newlocation,status,movers,newstatus;
	vector<int>route(END+1,-1);//记录已经考虑的状态路径
	queue<int>moveto;
	moveto.push(0x00);
	route[0]=0;
	while(!moveto.empty()&&route[END]==-1){
		status = moveto.front();//现在的状态
		moveto.pop();
		for(movers = 1;movers<=8;movers<<=1)
		{
			if(farmer(status)==static_cast<bool>(status&movers)){
				newstatus = status^(0x08|movers);
				if(safe(newstatus)&&route[newstatus]==-1)
				{
					route[newstatus] = status;
					moveto.push(newstatus);
				}
			}
				
		}
	}
	if(route[END]!=-1)
	{
		cout<<"The reverse path is:"<<endl;
		for(status = 15;status>=0;status = route[status])
		{
			cout<<"The status is"<<status<<endl;
			if(status==0)
				break;
		}
	}
	else
	{
		cout<<"No solution!"<<endl;
	}
}

