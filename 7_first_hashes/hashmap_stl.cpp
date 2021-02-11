#include<iostream>
#include<unordered_map>  //uses separate chaining
#include<map>            //uses BST so sorted output here but takes O(1) time instead of O(log n)
using namespace std;

int main(){
	map <string,int> h;   //change according to header file
	auto i=5;         //either this or write pair
	cout<<i<<endl;
	h.insert(make_pair("Mango",100));
	pair <string,int> p("Apple",150);         //another option
	h.insert(p);

	h["Pineapple"]=50;                        //another method
	string a="Mango";
	if(h.count(a)){
		cout<<"Price of "<<a<<" is "<<h[a]<<endl;
	}
	else{
		cout<<"Does not exist"<<endl;
	}

	for(auto i:h){
		cout<<i.first<<"-->"<<i.second<<endl;
	}

	return 0;
}	