#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

struct assign
{
	char var;
	int no;	
};

class calci
{
	char E[20];
	int opd[10];
	struct assign as[26];
	
	public:
	
	int compare(char ch,char a)
	{
		if(ch == a)
			return 1;
		else 
			return 0;
	}
	
	void operation()
	{
		int i,j,k=0,l,count=0;
		char opr;
		while(1)
		{
			gets(E);
			if(strcmp(E,"quit")==0)
				break;
				
			i=0;
			j=0;
			//k=0;
			int a=0,b,count=0;
			while(E[i]!='\0')
			{
				/*if(isdigit(E[i]))
					opd[j++]=E[i]-48;*/
				
				if(isdigit(E[i]))
				{
					do
					{
						a=a*10;
						b=E[i];
						b=b-48;
						a+=b;
						//count++;
						//cout<<a<<endl;
						i++;	
					}while(isdigit(E[i]));
					opd[j++]=a;
					a=0;
				}
				
				else
					if(E[i]=='+'||E[i]=='-'||E[i]=='*'||E[i]=='/')
					{
						opr=E[i];
						i++;
					}
					
				else 
					if(isalpha(E[i]))
					{
						i++;
						if(E[i] == '=')
						{
							opr=E[i];
							i++;
							if(isdigit(E[i]))
							{
								l=0;
								do
								{
									a=a*10;
									b=E[i];
									b=b-48;
									a+=b;
									//count++;
									//cout<<a<<endl;
									i++;	
								}while(isdigit(E[i]));
								for(l=0;l<26;l++)
								{
									if(compare(E[0],as[l].var)==1)
									{
										//as[k].var=E[i];
										as[l].no=a;
										a=0;
										break;
									}
									else
									{
										count++;
									}
								}
								if(count==26)
								{
									as[k].var=E[0];
									as[k++].no=a;
								}
							}
						}
						else
							if(E[i]=='+'||E[i]=='-'||E[i]=='*'||E[i]=='/')
							{
								i++;
								l=0;
								count=0;
								if(isalpha(E[i]))
								{
									while(count<26)
									{
										if(compare(E[i-2],as[count].var)==1)
											opd[0]=as[count].no;
											l++;
											
										if(compare(E[i],as[count].var)==1)
											opd[1]=as[count].no;
											l++;
											
										count++;
									}
									
								}
								
								else if(l>50)
										cout<<"\nWrong\n";
									
								else
									cout<<"\nWrong\n";
								opr=E[i-1];	
								break;
							}
						else
							cout<<"\nWrong Expression!\n";
					}
			}
			switch(opr)
			{
				case '+':
					cout<<opd[0]+opd[1]<<"\n";
				break;
				
				case '-':
					cout<<opd[0]-opd[1]<<"\n";
				break;
				
				case '*':
					cout<<opd[0]*opd[1]<<"\n";
				break;
				
				case '/':
					if(opd[1]!=0)
						cout<<(float)opd[0]/opd[1]<<"\n";
					else
						cout<<"\nCannot divide with zero\n";
				break;
				
				case '=':
					break;
				
				default:
					cout<<"\nWrong Expression\n";
			}
		}
	}
};

int main()
{
	calci c;
	c.operation();

	return 0;
}
asdfasfasf
