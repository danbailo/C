#include<stdio.h>
struct dbpoint{
	double x;
	double y;
	double z;
	int id;
};
int main(){
	struct dbpoint p = {22.1,33.2,4,0};
	double x=p.x + p.y + p.z;
	p.id=*(int*)&x;
	printf("%i\n",p.id);
	return 0;
}
