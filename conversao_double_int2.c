#include<stdio.h>
struct dbpoint{
	double x;
	double y;
	double z;
	int id;
};
int main(){
	struct dbpoint p = {22.0000001,33.2,4,0};
	
	double temp = (p.x + p.y + p.z);

	int* x=(int*)&temp;
	p.id=x[0]^x[1];
	printf("%i\n",p.id);
	return 0;
}
