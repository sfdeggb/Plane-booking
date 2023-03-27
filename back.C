#include "Pro.h"

extern int into_system();


LINK_ORDER* Delect_N(LINK_ORDER *head, char ter[12])
{
	LINK_ORDER *p1, *p2;


	p1 = p2 = head;

	if (head == NULL)
	{
		printf("the link is blank");
	}
	else
	{
		if (strcmp(p1->list, ter) == 0)
		{
			head = p1->next;
			free(p1);
		}

		else
		{
			while ((strcmp(p1->list, ter)!= 0) && p1->next != NULL)
			{
				p2 = p1;
				p1 = p1->next;
			}

			if (p1 != NULL)
			{
				p2->next = p1->next;
				free(p1);
			}

			else
			{
				printf("Not Find");
			}
		}
	}
		return head;
}


LINK_AIR_INFO* Change_N(LINK_AIR_INFO *head, char ter[12], int num)
{

	LINK_AIR_INFO *p1, *p2;
	//LINK_ORDER *head1 = NULL;

	p1 = p2 = head;

	if (head == NULL)
	{
		printf("the link is blank");
	}
	else
	{
			while ((strcmp(p1->list, ter)!= 0) && p1->next != NULL)
			{
				p2 = p1;
				p1 = p1->next;
			}

			if (p1 != NULL)
			{
				p1->seat_num = p1->seat_num + num;
			}

			else
			{
				printf("Not Find");
			}
	}
	

	return head;
	
}

void refund_tiket(char ideal_plane[], int num)
{
	FILE *fp1, *fp2;
	LINK_ORDER *p1, *p2, *head1 = NULL, *ter_p3, *Ohead;
	LINK_AIR_INFO *p3 = NULL, *p4=NULL, *head2 = NULL, *ter_p5 = NULL, *Ahead =NULL;
	AIR_INFO ter6;
	int n;

	int flag = 0;

	flag = into_system();

	if (flag == 0)
	{
		exit(7);
	}
	else
	{

		fp1 = fopen("order_info.txt", "r");
		//打印订单信息
		printf("\nthe information you ordered\n");
		//fread(&ter5, N, 1, fp);待定
		n = fscanf(fp1, "%s %s %s %s %s %d",
				ter6.list, ter6.start_place, ter6.destination, ter6.start_time, ter6.last_time, &ter6.seat_num);//先读到ter6的航班结构体

		while(n == 6)
		{
			printf("%s %s %s %s %s %d", 
				ter6.list, ter6.start_place, ter6.destination, ter6.start_time, ter6.last_time, ter6.seat_num);//读出到stdout中
		
			n = fscanf(fp1, "%s %s %s %s %s %d",
				ter6.list, ter6.start_place, ter6.destination, ter6.start_time, ter6.last_time, &ter6.seat_num);//先读到ter6的航班结构体

		}
		fclose(fp1);
		//进行退票操作
		fp1 = fopen("order_info.txt", "r");

		/*						修改订单文件					*/


		//建立链表
		p1  = p2 = (LINK_ORDER*)malloc(sizeof(LINK_ORDER));
		//fread(p2, N, 1, fp);
		n = fscanf(fp1, "%s %s %s %s %s %d",
		p1->list, p1->start_place, p1->destination, p1->start_time, p1->last_time, &(p1->seat_num));

		while(n==6)
		{
			
			if (head1 == NULL)
			{
				head1 = p1;
				p2->next = NULL;
			}
			else
			{
				p2->next = p1;
			}
			p2 = p1;
			p1 = (LINK_ORDER*)malloc(sizeof(LINK_ORDER));
			//fread(p1, N, 1, fp);
			n = fscanf(fp1, "%s %s %s %s %s %d",
		p1->list, p1->start_place, p1->destination, p1->start_time, p1->last_time, &(p1->seat_num));

		}

		p2->next = NULL;
		free(p1);
		fclose(fp1);
		//删除特定的节点
		Ohead = Delect_N(head1, ideal_plane);
		
		//清空文件并将链表写入
		//清空文件并将链表写入
		fp1 = fopen("order_info.txt", "w");

		ter_p3 = Ohead;

		while(ter_p3 != NULL)
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
					fprintf(fp1, "%s %s %s %s %s %d",
						ter_p3->list, ter_p3->start_place, ter_p3->destination, ter_p3->start_time, ter_p3->last_time, ter_p3->seat_num);

					ter_p3 = ter_p3->next;
				
				//goto ERROR1;
			//}

			//ter_p3 = ter_p3->next;
			
		}
	fclose(fp1);
		
	/*								finish					*/


	/*						修改航班文件					*/	

	fp2 = fopen("air_info.txt", "r+");
	//建立链表
		p3  = p4 = (LINK_AIR_INFO*)malloc(sizeof(LINK_AIR_INFO));
		//fread(p2, N, 1, fp);
		n = fscanf(fp2, "%s %s %s %s %s %d",
		p3->list, p3->start_place, p3->destination, p3->start_time, p3->last_time, &(p3->seat_num));

		while(n==6)
		{
			
			if (head2 == NULL)
			{
				head2 = p3;
				p4->next = NULL;
			}
			else
			{
				p4->next = p3;
			}
			p4 = p3;
			p3 = (LINK_AIR_INFO*)malloc(sizeof(LINK_AIR_INFO));
			//fread(p1, N, 1, fp);
			n = fscanf(fp2, "%s %s %s %s %s %d",
		p3->list, p3->start_place, p3->destination, p3->start_time, p3->last_time, &(p3->seat_num));

		}

		p4->next = NULL;

		free(p3);

		fclose(fp2);
		//修改特定的节点
		Ahead = Change_N(head2, ideal_plane, num);
		//清空文件并将链表写入
		fp2 = fopen("air_info.txt", "w");
		ter_p5 = Ahead;
		while(ter_p5 != NULL)
		{
					/*
					待定
					fwrite(p3->list, sizeof(p3->list), 1, fp1);
					fwrite(p3->start_place, sizeof(p3->start_place), 1, fp1);
					fwrite(p3->destination, sizeof(p3->destination), 1, fp1);
					fwrite(p3->state_time, sizeof(p3->state_time), 1, fp1);
					fwrite(p3->last_time, sizeof(p3->last_time), 1, fp1);
					fwrite(p3->seat_num, sizeof(p3->seat_num), 1, fp1);*/
					
					fprintf(fp2, "%s %s %s %s %s %d\n",
						ter_p5->list, ter_p5->start_place, ter_p5->destination, ter_p5->start_time, ter_p5->last_time, ter_p5->seat_num);

					ter_p5 = ter_p5->next;
				//}
				//goto ERROR2;
		}

			//ter_p5 = ter_p5->next;
			
		
		fclose(fp2);

			/*						finsh					*/
		printf("\n********************************************\n");
		printf("\nSUCCEED YOU REFUND THE TIKETS;\n");
		printf("\n********************************************\n");
	}
}