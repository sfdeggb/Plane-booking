#include"Pro.h"
char Select_Menu()
{
	/*主菜单显示函数*/
	

	printf("/************************************\\\n");

	printf("							\n");
	printf("*		飞机订票系统		 *\n");
	printf("							\n");
	printf("*			主菜单			 *\n");

	printf("*		1.查询机票		 *\n");
	printf("*		2.  订票		 *\n");
	printf("*		3.  改票		 *\n");
	printf("*		4.  退票		 *\n");
	printf("*		5.  退出		 *\n");
	printf("							\n");
	printf("*		请选菜单项（1-5）		 *\n");
	printf("/************************************\\\n");

	return getchar();
}