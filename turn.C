#include"Pro.h"

extern int into_system();
extern void reserve_tiket(char ideal_plane[12], int ideal_num);
extern void refund_tiket(char ideal_plane[], int num);

void change_tiket(char ideal_ari[], int num)
{
	FILE *fp;
	AIR_INFO ter5;
	int flag = 0;
	char C_tiket[12], R_tiket[12];
	int C_num, R_num;
	int n;
	flag = into_system();
	

	if (flag == 0)
	{
		exit(5);
	}
	else
	{
		if ((fp = fopen("order_info.txt", "r")) == NULL)
		{
			exit(6);	
		}
		//打印订单信息
		//fread(&ter5, N, 1, fp);
		
		n = fscanf(fp,"%s %s %s %s %s %d", 
			ter5.list, ter5.start_place, ter5.destination, ter5.start_time, ter5.last_time, &ter5.seat_num);//先读到航班结构体ter5中
		if (n == -1)
		{
			printf("\nYOU HAVEN'T RESREVE THE TICKET\n");
			exit(21);
		}
		while(n == 6)
		{
			printf("%s %s %s %s %s %d", 
				ter5.list, ter5.start_place, ter5.destination, ter5.start_time, ter5.last_time, ter5.seat_num);//从航班结构体中读到stdout中
		
			n = fscanf(fp,"%s %s %s %s %s %d", 
				ter5.list, ter5.start_place, ter5.destination, ter5.start_time, ter5.last_time, &ter5.seat_num);
		}
		
		// 输入要改的票并要重新订的票
		printf("\nplease input the tikets'information you wanted to change\n");
		scanf("%s", C_tiket);
		scanf("%d", &C_num);

		printf("\nplease input the tikets'information you wanted to order\n");
		scanf("%s", R_tiket);
		scanf("%d", &R_num);
		system("cls");
		//先退票
		refund_tiket(C_tiket, C_num);
		//再订票
		reserve_tiket(R_tiket, R_num);

		//system("cls");


	}
}