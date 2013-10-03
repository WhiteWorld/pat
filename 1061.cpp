#include <stdio.h>
#include <string.h>

char a[4][62];
char l,m;
int n;
char week[7][4]={
	"MON",
	"TUE",
	"WED",
	"THU",
	"FRI",
	"SAT",
	"SUN"
};
int main()
{
	for (int i = 0; i < 4; ++i)
		scanf("%s",a[i]);

	l='\0';
	m='\0';
	int last=0;
	for(int i=0;i<strlen(a[1]);i++)
		if(a[0][i]==a[1][i]&&a[0][i]>='A'&&a[0][i]<='G'){
			l=a[0][i];
			last = i;
			break;
		}
	for (int i = last + 1; i < strlen(a[1]); ++i)
		if(a[0][i]==a[1][i]){
			char t=a[0][i];
			if((t>='A'&&t<='N')||(t>='0'&&t<='9'))
			{
						m=t;
						break;
			}
		}

			n=0;
			for (int i = 0; i < strlen(a[2]); ++i)
			{

				if(a[2][i]==a[3][i])
				{
					char t=a[3][i];
					if((t>='a'&&t<='z')||(t>='A'&&t<='Z'))
					{
						n=i;
						break;
					}
				}
			}

			int h=0;
			if(m>='A'&&m<='N')
				h=10+m-'A';
			else if(m>='a'&&m<='n')
				h=10+m-'a';
			else if(m>='0'&&m<='9')
				h=m-'0';
			printf("%s %02d:%02d\n",week[l-'A'],h,n);

			return 0;
		}