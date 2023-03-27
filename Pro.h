#ifndef PRO_H
#define PRO_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<windows.h>

#define N sizeof(AIR_NFO)
#define M sizeof(ORDER)
#define J sizeof(CUSTOMER_INFO)

typedef struct air_info		/*航班信息*/
{
	char list[12];		
	char start_place[20];
	char destination[20];
	char start_time[12];
	char last_time[12];
	int seat_num;
}AIR_INFO;

typedef struct air_info_link		/*建立链表之用*/
{
	char list[12];		
	char start_place[20];
	char destination[20];
	char start_time[12];
	char last_time[12];
	int seat_num;
	struct air_info_link *next;
}LINK_AIR_INFO;

typedef struct order	/*订单信息*/
{
	char list[12];
	char start_place[20];
	char destination[20];
	char start_time[12];
	char last_time[12];
	int seat_num;
}ORDER;

typedef struct link_order/*建立订单链表*/
{
	char list[12];
	char start_place[20];
	char destination[20];
	char start_time[12];
	char last_time[12];
	int seat_num;
	struct link_order *next;
}LINK_ORDER;

typedef struct customer_info
{
	char login_name[20];
	char pass_word[8];
}CUSTOMER_INFO;

/*用户登录函数*/
int into_system(void);

/*飞机订票系统函数声明*/
int search_info(void);
void reserve_tiket(char ideal_plane[12], int ideal_num);
void change_tiket(char ideal_ari[], int num);
void refund_tiket(char ideal_plane[], int num);

#endif