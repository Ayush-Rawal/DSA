#include <iostream>

// Linear : Array, Linked list
// Non-Linear : Tree
// Tree is a subset of graph (A graph with no cycle is a tree)

void enterArray(char a[],size_t size)
{
	for (int i=0;i<size;i++){
		std::cin>>a[i];
	}
}

void printArray(char a[],size_t size)
{
	for (int i=0;i<size;i++){
		std::cout<<a[i]<<" ";
	}
		std::cout<<std::endl;
}

void reverse(char a[],size_t size)
{
    int i;
    for(i=0;i<size/2;i++){
        // temp=a[i];
        // a[i]=a[size-i-1];
        // a[size-i-1]=temp;
		a[i]=a[i]+a[size-i-1];
		a[size-i-1]=a[i]-a[size-i-1];
		a[i]=a[i]-a[size-i-1];
    }
}

void q1()
{
	const size_t n =10;
	char a[n];
	std::cout<<"Enter array (of size "<<n<<" )"<<std::endl;
	enterArray(a,n);
	std::cout<<std::endl<<"Original array:"<<std::endl;
	printArray(a,n);
	reverse(a,n/2);
	reverse(a+n/2,n/2);
	std::cout<<std::endl<<"Reversed array"<<std::endl;
	printArray(a,n);
}

void enterArray(int a[],size_t size)
{
	for (int i=0;i<size;i++){
		std::cin>>a[i];
	}
}

void printArray(int a[],size_t size)
{
	for (int i=0;i<size;i++){
		std::cout<<a[i]<<" ";
	}
	std::cout<<std::endl;
}

void sort_asc(int a[],size_t size, unsigned int inc = 1)
{
    printArray(a,size);
	for(int i=0;i<size;i=i+inc){
		int small=a[i], pos = i;
		for(int j=i+inc;j<size;j=j+inc){
			if(a[j]<small){
				small=a[j];
				pos=j;
			}
		}

		small = a[i];
		a[i]=a[pos];
		a[pos]=small;
	}
    printArray(a,size);
	std::cout<<std::endl<<std::endl;
}

void sort_des(int a[],size_t size,unsigned int inc = 1)
{
    printArray(a,size);
    for(int i=0;i<size;i=i+inc){
		int big=a[i], pos = i;
		for(int j=i+inc;j<size;j=j+inc){
			if(a[j]>big){
				big=a[j];
				pos=j;
			}
		}

		big = a[i];
		a[i]=a[pos];
		a[pos]=big;
	}
    printArray(a,size);
	std::cout<<std::endl<<std::endl;
}

void q3()
{
	const size_t n=10;
	int a[n];
	std::cout<<"Enter array (of size "<<n<<" )"<<std::endl;
	enterArray(a,n);
	sort_asc(a,n,2);
	sort_des(a+1,n-1,2);
	std::cout<<std::endl;
	printArray(a,n);
}

int main(int argc,char* argv[])
{

// reverse first and second half of an array seperately
// Sort alternatively
	q1();
	std::cout<<std::endl;
	int a[10];
	q3();
	return 0;
}
