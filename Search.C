/*
		������Ϣ�Ĳ�ѯ

���ݽṹ���ṹ��
		  ����
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

	//�򿪺�����Ϣ�ļ�
	if ((fp = fopen("air_info.txt","r")) == NULL)
	{
		printf("Please exam the source file'route\n");
		exit(1);
	}
	/*�����ʽ˵��*/
	printf("PLEASE FOLLOW THE BELOW RULES WHEN YOU SEARCH\n\n");
	printf("the air's sytax: ����MT1234 \n");
	printf("the air's time: xxxx-xx-xx\n");
	printf("the air's start or last place:xxxx\n");

tt:printf("the way you want to search:\n 1-air\n 2-air_time\n 3-air_place\n");
	scanf("%3d", &way_num);

	printf("\nPlease intput the information you wanted\n");
	scanf("%s", input_info);
	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	
	//ֱ��Դ�ļ���д��ѯ
	//fread(&ter, N, 1, fp);
	n = fscanf(fp, "%s %s %s %s %s %d\n",
		ter.list, ter.start_place, ter.destination, ter.start_time, ter.last_time, &ter.seat_num);

	while(n == 6)
	{	// �������������������룻
		if(way_num == 0)
		{
			goto tt;
		}
		//���������кŲ�ѯ
		if (way_num == 1)
		{
			if (strcmp(ter.list, input_info) == 0)
			{
				flag = 1;
				printf("%s %s-%s %s %s %d\n", 
					ter.list, ter.start_place, ter.destination, ter.start_time, ter.last_time, ter.seat_num);
			}

		}
		// ������ʱ���ѯ
		if (way_num == 2)
		{
			if (strcmp(ter.start_time, input_info) == 0)
			{
				flag = 1;
				printf("%s %s-%s %s %s %d", 
					ter.list, ter.start_place, ter.destination, ter.start_time, ter.last_time, ter.seat_num);
			}
		}
		//��Ŀ�ĵز�ѯ
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
