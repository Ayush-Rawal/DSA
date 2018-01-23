#include<iostream>
#include<cstring>

struct student {
	char id[13];
	char name[30];
	student *s;
};

int main(int argc, char *argv[])
{
	student *a,*b,*c;
	strcpy(a->id,"2017KUCP1036");
	strcpy(a->name,"Ayush Rawal");
	strcpy(b->id,"2017KUCP1035");
	strcpy(b->name,"Suresh");
	strcpy(c->id,"2017KUCP1037");
	strcpy(c->name,"Mayank");
	a->s = b;
	b->s = c;
	c->s = NULL;
	return 0;
}