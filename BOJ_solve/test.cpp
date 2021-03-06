#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int lotto[6],num[6];
int arr[45],check[46];
char input[100],gar;
int main() {
	srand(time(NULL));
	printf("1.자동 2.수동 3.반자동\n");
	int op;
	scanf("%d",&op);
	for(int i = 0;i < 45;i++) arr[i] = i+1;
	for(int i = 0;i < 45;i++) swap(arr[i],arr[rand()%45]);
	for(int i = 0;i < 6;i++) lotto[i] = arr[i];
	switch(op) {
		case 1:
			for(int i = 0;i < 6;i++) printf("%d ",lotto[i]);
			printf("\n");
			break;
		case 2:
			for(int i = 0;i < 6;i++) scanf("%d ",lotto[i]);
			for(int i = 0;i < 6;i++) printf("%d ",lotto[i]);
			printf("\n");
			break;
		default:
			scanf("%c",&gar);
			scanf("%[^\n]",&input);
			scanf("%c",&gar); // 개행 입력됨
			int len = strlen(input),n = 0;
			for(int i = 0;i < len;i++) {
				if(input[i] != ' ') num[n] = num[n]*10+(input[i]-'0');
				else {
					check[num[n]] = 1;
					n++;
				}
			}
			n++;
			int renum = 0;
			for(int i = 0;i < 45;i++) {
				if(check[i+1] == 0) {
					arr[renum] = i+1;
					renum++;
				}
			}
			for(int i = 0;i < renum;i++) {
				swap(arr[i],arr[rand()%renum]);
			}
			for(int i = 0;i < n;i++) {
				printf("%d ",num[i]);
			}
			for(int i = 0;i < 6-n;i++) {
				printf("%d ",arr[i]);
			}
			printf("\n");
			break;
	}
	return 0;
}

x, y // 바꿔야 할 두 수
int tmp = x;
x = y;
y = tmp;