#include"Pro.h"

void reserve_tiket(char ideal_plane[12], int ideal_num)
{
	FILE *fp1, *fp2;
	char re_plane[12];
	int re_num;
	int n = 0;
	LINK_AIR_INFO *p1, *p2, *head = NULL;
	LINK_AIR_INFO *p3;
	
	int flag = 0;
	flag = into_system();

	// 如果未能进入系统
	if (flag == 0)
	{
		exit(3);
	}
	else
	{
		//打开相关文件
		if (((fp1 = fopen("air_info.txt", "r")) == NULL) ||
			((fp2 = fopen("order_info.txt", "w")) == NULL))

		{
			printf("please operate again");
			exit(4);
		}
		
		strcpy(re_plane, ideal_plane);
		re_num = ideal_num;
		// 建立航班信息链表
		p1  = p2 = (LINK_AIR_INFO*)malloc(sizeof(LINK_AIR_INFO));
		//fread(p2, N, 1, fp);
		n = fscanf(fp1, "%s %s %s %s %s %d\n",
		p1->list, p1->start_place, p1->destination, p1->start_time, p1->last_time, &(p1->seat_num));

		while(n==6)
		{
			
			if (head == NULL)
			{
				head = p1;
				p2->next = NULL;
			}
			else
			{
				p2->next = p1;
			}
			p2 = p1;
			p1 = (LINK_AIR_INFO*)malloc(sizeof(LINK_AIR_INFO));
			//fread(p1, N, 1, fp);
			n = fscanf(fp1, "%s %s %s %s %s %d\n",
		p1->list, p1->start_place, p1->destination, p1->start_time, p1->last_time, &(p1->seat_num));

		}

		p2->next = NULL;
		free(p1);

		//查找目标航班内容
		p3 = head;
		while(p3 != NULL)
		{
			if (strcmp(p3->list, re_plane) == 0)
			{
				//改变链表中的值
				p3->seat_num = p3->seat_num - re_num;
				/*
				待定
				fwrite(p3->list, sizeof(p3->list), 1, fp);
				fwrite(p3->start_place, sizeof(p3->start_place), 1, fp);
				fwrite(p3->destination, sizeof(p3->destination), 1, fp);
				fwrite(p3->state_time, sizeof(p3->state_time), 1, fp);
				fwrite(p3->last_time, sizeof(p3->last_time), 1, fp);
				fwrite(re_num, sizeof(int), 1, fp);
				*/
				//写入订单信息
				fprintf(fp2, "%s %s %s %s %s %d\n",
						p3->list, p3->start_place, p3->destination, p3->start_time, p3->last_time, re_num);
		
				printf("\n********************************************\n");
				printf("SUCCEND YOU RESERVE THE TIKETS");
				printf("\n********************************************\n");

				/*将链表中的内容写入航班文件中*/
				fclose(fp1);
				fp1 = fopen("air_info.txt", "w");// 清空内容
				p3 = head;
				while(p3 != NULL)
				{
					/*
					待定
					fwrite(p3->list, sizeof(p3->list), 1, fp1);
					fwrite(p3->start_place, sizeof(p3->start_place), 1, fp1);
					fwrite(p3->destination, sizeof(p3->destination), 1, fp1);
					fwrite(p3->state_time, sizeof(p3->state_time), 1, fp1);
					fwrite(p3->last_time, sizeof(p3->last_time), 1, fp1);
					fwrite(p3->seat_num, sizeof(p3->seat_num), 1, fp1);
					*/
					fprintf(fp1, "%s %s %s %s %s %d\n",
						p3->list, p3->start_place, p3->destination, p3->start_time, p3->last_time, p3->seat_num);

					p3 = p3->next;
				}
				goto sta;
			}

			p3 = p3->next;
			
		}
	sta:
		fclose(fp1);
		fclose(fp2);
	}

}