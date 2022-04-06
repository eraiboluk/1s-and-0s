#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 32

typedef struct{
    int item[MAX];
    int top;
}stack;

void intStack(stack *s){ s->top=0; }

int isEmpty(stack *s){
    if(s->top==0)
        return 1;
    return 0;
}

int isFull(stack *s){
    if(s->top==MAX)
        return 1;
    return 0;
}

int push(int x, stack *s){
    if(isFull(s)==1)
        return 1;
    s->item[s->top++]=x;
    return 0;
}

int pop(stack *s, int *x){
    if(isEmpty(s)==1)
        return 1;
    s->top--;
    *x=s->item[s->top];
    return 0;
}

int top(stack *s, int *x){

    int adr;
    if(isEmpty(s))
        return 1;
    adr=s->top-1;
    *x=s->item[adr];
    return 0;
}

char *toBinary(int x){
	int i,j=0;
	
    if (x<256){
    	
        char *binary=(char*)malloc(8*sizeof(char));
        
        for(i=7;i>=0;i--){
        	if(x-pow(2,i)>=0){
				*(binary+j)='1';
				x-=pow(2,i);
				
			}
        	else{
        		*(binary+j)='0';
			}
        	j++;
		}
		binary[j]='\0';
        return binary;
    }
    else if (x<65536){
    	
        char *binary=(char*)malloc(16*sizeof(char));
        
        for(i=15;i>=0;i--){
        	if(x-pow(2,i)>=0){
				*(binary+j)='1';
				x-=pow(2,i);
				
			}
        	else{
        		*(binary+j)='0';
			}
        	j++;
		}
		binary[j]='\0';
        return binary;
    }
}

char *toNegBinary(int x){
	
	int	i,j=0,elde=1;
	
	
	if(x>-129){
		char *binary=(char*)malloc(8*sizeof(char));
		
		binary[j]='1';
		x*=-1;
		for(i=7;i>=0;i--){
			if(x-pow(2,i)>=0){
				*(binary+j)='0';
				x-=pow(2,i);
				
			}
        	else{
        		*(binary+j)='1';
			}
        	j++;
		}
		*(binary+j)='\0';
		j--;
		while(elde==1){
			if(*(binary+j)=='1'){
				*(binary+j)='0';
				j--;
			}
			else{
				*(binary+j)='1';
				elde=0;
			}		
		}
		return binary;
			
	}
	
	else if(x>-32769){
		char *binary=(char*)malloc(16*sizeof(char));
		
		binary[j]='1';
		j++;
		x*=-1;
		for(i=15;i>=0;i--){
			if(x-pow(2,i)>=0){
				*(binary+j)='0';
				x-=pow(2,i);
				
			}
        	else{
        		*(binary+j)='1';
			}
        	j++;
		}
		*(binary+j)='\0';
		j--;
		while(elde==1){
			if(*(binary+j)=='1'){
				*(binary+j)='0';
				j--;
			}
				
			else{
				*(binary+j)='1';
				elde=0;
			}		
		}
		return binary;
			
	}
}

char countBinary(char *a, stack *s){
	int i=0, b;
	char temp=*(a+i);
	
	
	while(*(a+i)!='\0'){
		if(*(a+i)==temp)
			push(1,s);
		else{
			if(1==pop(s,&b)){
				if(temp=='1')
					temp='0';
				else
					temp='1';
				push(1,s);
			}
		}
		i++;	
	}
	return temp;
}

int main(){
    int x;
    char temp;
    
    stack *s=(stack*)malloc(sizeof(stack));
    intStack(s);
    printf("Sayi giriniz...\n\n");
    scanf("%d",&x);
    
    if(x>=0){
    	printf("%s\n\n",toBinary(x));
    	temp=countBinary(toBinary(x),s);
	}
	else{
		printf("%s\n\n",toNegBinary(x));
    	temp=countBinary(toNegBinary(x),s);
	}
    
    if(isEmpty(s)==1)
    	printf("0 ve 1 ler esit sayida\n\n");
    else
    	printf("%c'ler %d daha fazla", temp, s->top);
    return 0;
}

