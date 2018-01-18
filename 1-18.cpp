#include<iostream>
#include<cmath>

void enterArray(int *a,size_t size)
{
	for (int i=0;i<size;i++){
		std::cin>>*(a+i);
	}
}
void enterArray(char *a,size_t size)
{
	for (int i=0;i<size;i++){
		std::cin>>*(a+i);
	}
}

void printArray(int *a,size_t size)
{
	for (int i=0;i<size;i++){
		std::cout<<*(a+i)<<" ";
	}
	std::cout<<std::endl;
}

void printArray(char *a,size_t size)
{
	for (int i=0;i<size;i++){
		std::cout<<*(a+i)<<" ";
	}
	std::cout<<std::endl;
}

void sort_asc(int *a,size_t size, unsigned int inc = 1)
{
	for(int i = 0 ; i < size; i += inc){
		int small = *(a+i), pos = i;
		for(int j=i+inc;j<size;j=j+inc){
			if(*(a+j)<small){
				small=*(a+j);
				pos=j;
			}
		}
		small = *(a+i);
		*(a+i)=*(a+pos);
		*(a+pos)=small;
	}
}

void q1()
{
	size_t n;
	int *p;
	std::cout<<"How many numbers do you want to sort?"<<std::endl;
	std::cin>>n;
	p = (int*)calloc(n,sizeof(int));
	std::cout<<"Enter numbers"<<std::endl;
	enterArray(p,n);
	sort_asc(p,n);
	std::cout<<"Sorted array is:"<<std::endl;
	printArray(p,n);
}

void q2()
{
	size_t size;
	int n=1,*p;
	std::cout<<"How many numbers are there?"<<std::endl;
	std::cin>>size;
	p = (int*)calloc(size,sizeof(int));
	std::cout<<"Enter numbers"<<std::endl;
	enterArray(p,size);
	std::cout<<"Which smallest element do you want? ex: second smallest, first smallest"<<std::endl;
	std::cin>>n;
	sort_asc(p,size);
	std::cout<<n<<"th smallest element is: "<<*(p+n-1)<<std::endl;
}

struct point{
    int x,y;
};

void enterPoints(point* p, size_t size)
{
	for(int i=0;i<size;i++){
		std::cin>>(p+i)->x>>(p+i)->y;
	}
}

float computeDist(point a,point b)
{
    return sqrt(fabs(( a.x*a.x + a.y*a.y ) - ( b.x*b.x + b.y*b.y )));
}

float computeSmallestDistance(point *p,size_t size)
{
    int i,j;
    float min = computeDist(*(p+0),*(p+1));
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if( ( i==0 && j==1 ) || ( i==j ))
            continue;
            float small = computeDist(*(p+i),*(p+j));
            if(small<min)
            min=small;
        }
    }
    return min;
}

void q3()
{
	size_t n;
	point *p;
	std::cout<<"How many points are there?"<<std::endl;
	std::cin>>n;
	p = (point*)calloc(n,sizeof(point));
	std::cout<<"Enter points"<<std::endl;
	enterPoints(p,n);
	std::cout<<"Smallest distance between any two points is: "<<computeSmallestDistance(p,n)<<std::endl;
}

void reverse(int *a,size_t size)
{
    int i;
    for(i=0;i<size/2;i++){
        int temp=a[i];
        a[i]=a[size-i-1];
        a[size-i-1]=temp;
    }
}
void reverse(char *a,size_t size)
{
    int i;
    for(i=0;i<size/2;i++){
        char temp=a[i];
        a[i]=a[size-i-1];
        a[size-i-1]=temp;
    }
}

void q4()
{
	size_t size;
	char choice;
	std::cout<<"How many elements in sequence"<<std::endl;
	std::cin>>size;
	std::cout<<"Numbers(n) or characters(c)?"<<std::endl;
	std::cin>>choice;
	// seq = choice=='n'?:;
	if(choice=='n'){
		int *seq;		
		seq=(int*)calloc(size,sizeof(int));
	std::cout<<"Enter sequence"<<std::endl;
	enterArray(seq,size);
	reverse(seq,size);
	std::cout<<"Reversed sequence is: "<<std::endl;
	printArray(seq,size);
	return;
	} else if (choice=='c'){
		char *seq;
		seq=(char*)calloc(size,sizeof(char));
	std::cout<<"Enter sequence"<<std::endl;
	enterArray(seq,size);
	reverse(seq,size);
	std::cout<<"Reversed sequence is: "<<std::endl;
	printArray(seq,size);
	return;
	}
	std::cout<<"Invalid choice, exiting"<<std::endl;
}

int main(int argc, char* argv[])
{
	// q1();// Sort n numbers
	// q2();// Find nth smallest numbers
	// q3();// Find closest pair among n points
	q4();// Reverse an array/name 
	return 0;
}