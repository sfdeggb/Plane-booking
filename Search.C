/*
		航班信息的查询

数据结构：结构体
		  整型
*/
#include"Pro.h"

int search_info(void)
{
	FILE *fp;
	char input_info[50];
	AIR_INFO ter;
	int way_num = 0;
	int flag = 0;
	int n = 0;

	//打开航班信息文件
	if ((fp = fopen("air_info.txt","r")) == NULL)
	{
		printf("Please exam the source file'route\n");
		exit(1);
	}
	/*输入格式说明*/
	printf("PLEASE FOLLOW THE BELOW RULES WHEN YOU SEARCH\n\n");
	printf("the air's sytax: 西航MT1234 \n");
	printf("the air's time: xxxx-xx-xx\n");
	printf("the air's start or last place:xxxx\n");

tt:printf("the way you want to search:\n 1-air\n 2-air_time\n 3-air_place\n");
	scanf("%3d", &way_num);

	printf("\nPlease intput the information you wanted\n");
	scanf("%s", input_info);
	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	
	//直接源文件读写查询
	//fread(&ter, N, 1, fp);
	n = fscanf(fp, "%s %s %s %s %s %d\n",
		ter.list, ter.start_place, ter.destination, ter.start_time, ter.last_time, &ter.seat_num);

	while(n == 6)
	{	// 如果输入错误，则重新输入；
		if(way_num == 0)
		{
			goto tt;
		}
		//按航班序列号查询
		if (way_num == 1)
		{
			if (strcmp(ter.list, input_info) == 0)
			{
				flag = 1;
				printf("%s %s-%s %s %s %d\n", 
					ter.list, ter.start_place, ter.destination, ter.start_time, ter.last_time, ter.seat_num);
			}

		}
		// 按出发时间查询
		if (way_num == 2)
		{
			if (strcmp(ter.start_time, input_info) == 0)
			{
				flag = 1;
				printf("%s %s-%s %s %s %d", 
					ter.list, ter.start_place, ter.destination, ter.start_time, ter.last_time, ter.seat_num);
			}
		}
		//按目的地查询
		if (way_num == 3)
		{
			if (strcmp(ter.destination, input_info) == 0)
			{
				flag = 1;
				printf("%s %s-%s %s %s %d\n", 
					ter.list, ter.start_place, ter.destination, ter.start_time, ter.last_time, ter.seat_num);
			}
		}

		n = fscanf(fp, "%s %s %s %s %s %d\n",
		ter.list, ter.start_place, ter.destination, ter.start_time, ter.last_time, &ter.seat_num);

	}

	return flag;
	
}

