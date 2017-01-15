#include<iostream>
#include<stack>
using namespace std;
//Xac dinh muc do uu tien cua toan tu
int xacDinh_uutien(char x)
{
	if(x == '+') return 1;
	else if(x == '*') return 2;
	return 3;
}

int main(){
	freopen("input.txt","r",stdin);
	char c[1000]= {};
	cin>>c;
	stack<char> s;
	char token,x;
	char tg[1000] = {};
	int j = 0;
	for(int i = 0;c[i] != '\0';i++)
		//Duyet tu dau toi cuoi chuoi
	{
		token = c[i];
		if(token >= '0' && token <= '9') tg[j++] = token;
		else {
			while(!s.empty() && xacDinh_uutien (token) <= xacDinh_uutien (s.top())){
				x = s.top();
				s.pop();
				tg[j++] = x;
			}
			s.push(token);
		}
	}
	while(!s.empty()){
		x = s.top();
		s.pop();
		tg[j++] = x;
	}
	tg[j] = '\0';
	for(int i = 0;tg[i] != '\0';i++)
	{
		cout<<tg[i];
	}
	cout<<endl;
	//Tinh bieu thuc
	stack<int> s1;
	for(int i = 0; tg[i] != '\0';i++){
		x = tg[i];
		int result = 0;
		if(x>='0' && x <= '9') {
			x = x - 48;
			s1.push(x);

		}
		else{
			int op1 = 0,op2 = 0;
			op1 = s1.top();
			s1.pop();
			op2 = s1.top();
			s1.pop();
			
			if(x == '+')  result = op1 + op2;
			else if(x == '*') result = op1 * op2;
			s1.push(result);
		}
		
	}
	cout<<s1.top();
	return 0;

}