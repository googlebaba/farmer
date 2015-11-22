#include <vector>
#include <queue>
#include <iostream>
bool farmer(int status);//确定农夫的位置
bool wolf(int status);//确定狼的位置
bool cabbage(int status);//确定白菜的位置
bool goat(int status);//确定山羊的位置
bool safe(int status);//判断此时的状态是否为安全
void slove();//处理函数