#include "pro.h"

extern char Select_Menu(void);
extern int into_system(void);
extern int search_info(void);
extern void reserve_tiket(char ideal_air[], int ideal_num);
extern void change_tiket(char ideal_ari[], int num);
extern void refund_tiket(char ideal_plane[], int num);

int main(void)
{
	char ch;
	char ideal_plane[12], C_plane[12], R_plane[12];
	int ideal_num, C_num, R_num;
	int flag;

	ch = Select_Menu();
	system("cls");

	switch (ch)
	{
		/*��ѯ����*/
		case ('1'):
		{
			flag = search_info();
			printf("%d", flag);
			break;
		}
		/*��Ʊ����*/
		case ('2'):
		{
			printf("please input the air's list and the number of you wanteed to reserve:\n");
			scanf("%s %d", ideal_plane, &ideal_num);

			reserve_tiket(ideal_plane, ideal_num);
			break;
		}
		/*��Ʊ����*/
		case ('3'):
		{
			printf("please input the ari's list information that you want to change\n:");
			scanf("%s", C_plane);
			scanf("%d", &C_num);
			change_tiket(C_plane, C_num);
			break;
		}
		/*��Ʊ����*/
		case ('4'):
		{
			printf("please input the air's list and num that you want back:\n");
			scanf("%s", R_plane);
			scanf("%d", &R_num);
			refund_tiket(R_plane, R_num);
			break;
	
		}
		/*�˵��˳�*/
		case ('5'):
		{
			exit(0);	
		}
	}

	return 0;
}