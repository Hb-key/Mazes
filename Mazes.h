#pragma once

#define MAX_ROW 6
#define MAX_COL 6
//����ջ��Ԫ�ص���������
#define SeqStackType Point
//˳���ʵ��ջʱ����ṹ��
typedef struct SeqStack
{
	//���ڴ��ջ��Ԫ�أ�֮���Զ���Ϊָ�����Ͷ�����ָ����С���������ͣ���Ϊ�˷��㶯̬�����ڴ�
	SeqStackType* data;
	//������ʾջ����ЧԪ�ظ���
	size_t size;
	//������ʾջ�״�����Ŀռ����󳤶�
	size_t capacity;
}SeqStack;
//��������Թ��Ľṹ��
typedef struct Maze
{
	//�Թ���ͼ
	int map[MAX_ROW][MAX_COL];
}Maze;
//�����Թ���ͼ��ÿ��λ�ã��ɶ�ά������к��о���
typedef struct Point
{
	int row;
	int col;
}Point;
/*==========��������==========*/
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

