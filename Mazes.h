#pragma once

#define MAX_ROW 6
#define MAX_COL 6
//定义栈中元素的数据类型
#define SeqStackType Point
//顺序表实现栈时定义结构体
typedef struct SeqStack
{
	//用于存放栈的元素，之所以定义为指针类型而不是指定大小的数组类型，是为了方便动态开辟内存
	SeqStackType* data;
	//用来表示栈的有效元素个数
	size_t size;
	//用来表示栈首次申请的空间的最大长度
	size_t capacity;
}SeqStack;
//定义关于迷宫的结构体
typedef struct Maze
{
	//迷宫地图
	int map[MAX_ROW][MAX_COL];
}Maze;
//定义迷宫地图的每个位置，由二维数组的行和列决定
typedef struct Point
{
	int row;
	int col;
}Point;
/*==========函数声明==========*/
void MazeInit(Maze* maze);
void MazePrint(Maze* maze);
int CanStay(Maze* maze, Point cur);
void Mark(Maze* maze, Point cur);
int IsExit(Maze* maze, Point cur, Point entry);
void _GetPath(Maze* maze, Point cur, Point entry);
void SeqStackInit(SeqStack* stack);
void SeqStackDestroy(SeqStack* stack);
void SeqStackPrintChar(SeqStack* stack, char* msg);
void SeqStackPush(SeqStack* stack, SeqStackType value);
SeqStackType* SeqStackResize(SeqStack* stack);
int SeqStackPop(SeqStack* stack);
int SeqStackTop(SeqStack* stack, SeqStackType* value);
void SeqStackPrintPoint(SeqStack* stack);
void _GetShortPath(Maze* maze, Point cur, Point entry, SeqStack* cur_stack, SeqStack* short_stack);
void SeqStackCopy(SeqStack* cur_stack, SeqStack* short_stack);
int CanStayWithCircle(Maze* maze, Point prev, Point cur);
void MarkWithCircle(Maze* maze, Point prev, Point cur);
void MazeShortPathWithCircle(Maze* maze);
void _GetShortPathWithCircle(Maze* maze, Point prev, Point cur, Point entry, SeqStack* cur_stack, SeqStack* short_stack);

