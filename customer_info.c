#include"Pro.h"

int into_system(void)
{
	FILE *fp;
	char ch[3];
	CUSTOMER_INFO ter3;
	CUSTOMER_INFO ter4;

	if ((fp = fopen("cusmer.txt", "r+")) == NULL)
	{
		printf("please try again after a minute");
		exit(4);
	}

AA:printf("Hvae you owned our count: Y/N\n");
	scanf("%s",ch);

	switch(ch[0])
	{
		case('Y'):
			//用户输入待检测的在ter3中
			BB:printf("please input you count and password\n");
					scanf("%s %s", ter3.login_name, ter3.pass_word);

					while ((fscanf(fp, "%s %s", ter4.login_name, ter4.pass_word)) == 2)
					{
						if ((strcmp(ter3.login_name, ter4.login_name) == 0) && 
							((strcmp(ter3.pass_word, ter4.pass_word)) == 0))
						{
							printf("\nYOU HAVE SUCCEND GOINTO\n");
							return 1;
						}
					}
					break;
			
		case('N'):
			
				printf("please input you count and password\n");
				scanf("%s %s", ter3.login_name, ter3.pass_word);

				//将文件指针移到末尾
				fseek(fp, 0, 2);
				fprintf(fp, "%s %s", ter3.login_name, ter3.pass_word);
				printf("\nINSGETION SUCCEND\n");
				rewind(fp);
				// 重新登录
				goto BB;
				break;
		default:
			goto AA;
	}

	return 1;
}
