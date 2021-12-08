#include<iostream>
#include<vector>

using namespace std;
int error(){
	try{
		throw 0;
	}
	catch(int expn){
		try{
			throw 4;
		}
		catch(int test){
			throw;
		}
	}
}
int main(){
	int a[2];
	try{
		cout<<"no error"<<endl;
		int b = error();
		cout<<b<<endl;
	}
	catch(int expn){
		cout<<"Error"<<expn<<endl;
	}

}