#include <iostream>
#include <vector>
using namespace std;

void ordernar(int v[],int ord){
	int c1,c2,aux;
	  for(c1=0;c1<=8;c1++){
	    for(c2=0;c2<8;c2++){
	      if(ord==1){
	        if(v[c2]>v[c2+1]){
	          aux=v[c2];
	          v[c2]=v[c2+1];
	          v[c2+1]=aux;
	        }
	      }else{
	        if(v[c2]<v[c2+1]){
	          aux=v[c2];
	          v[c2]=v[c2+1];
	          v[c2+1]=aux;
	        }
	      }
	    }
	  }

}

int main(int argc, char const *argv[])
{
	int v[]={12,23,2,45,39,20,50,24};
	ordernar(v,1);// 1 : ascendente y 2:decendente

	for(int i=0;i<8;i++)
		cout << v[i]<<endl;
	return 0;
}