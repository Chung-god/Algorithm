#include<cstdio>
#include<algorithm>
int main() {
	int t[9],i,j,s=0;
	for(i=0;i<9;s+=t[i],i++)scanf("%d",&t[i]); //입력을 받으면서 합에 더해줌
	std::sort(t,t+9);//정렬
	for(i=0;i<8;i++)for(j=i+1;j<9;j++)if(s-t[i]-t[j]==100){//반복문을 통해서 9명중 2명을 빼서 100되게 함
		t[i]=t[j]=0;// 그 두 난쟁이 빼 버림
		for(i=0;i<9;i++)if(t[i])printf("%d\n",t[i]);
		return 0;
	}
}