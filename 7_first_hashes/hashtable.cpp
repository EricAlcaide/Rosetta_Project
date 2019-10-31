#include<iostream>
using namespace std;

template <typename T>				//we can increase the no. of datatypes 
class node{
public:
	string key;
	T value;
	node<T>* next;

	node(string k,T val){
		key=k;
		value=val;
		next=NULL;
	}

		~node(){                    //first delete uska next to delete the node
			if(next!=NULL){
				delete next;
				next=NULL;
			}
		}
};

template <typename T>
class hashmap{
	node<T>** Bucket;             //dynamic
	int cs;
	int ts;  					  //table ka size

	int hashFn(string key){
		int ans=0;
		int p=1;                  //prime no.

		for(int i=0;key[i]!='\0';i++){
			ans+=key[i]*p;
			p=p*37;

			p%=ts;                //(a*b)%37=(a%37)*(b%37)
			ans%=ts;
		}
		return ans;
	}

	void rehash(){
		node<T>** oldBucket=Bucket;
		int oldts=ts;

		ts=2*ts;
		cs=0;
		Bucket=new node<T>*[ts];
		for(int i=0;i<ts;i++){         
			Bucket[i]=NULL;
		}

		for(int i=0;i<oldts;i++){
			node<T>* temp=oldBucket[i];
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp=temp->next;
			}
			delete oldBucket[i];
		}
		delete []oldBucket;           //it's an array
	}	

public:
	hashmap(int ms=7){   		 //max size
		cs=0;
		ts=ms;
		Bucket=new node<T>*[ts]; 

		for(int i=0;i<ts;i++){          //pointers ki bucket aise create hoti hai
			Bucket[i]=NULL;
		}      
	}

	void insert(string key,T value){
		int i=hashFn(key);

		node<T>* n=new node<T>(key,value);
		n->next=Bucket[i];
		Bucket[i]=n;
		cs++;

		float load_factor=cs/(1.0*ts);

		if(load_factor>0.7){
			rehash();
		}
	}

	T* search(string key){             //so we can return null, we make it a pointer
		int i=hashFn(key);

		node<T>* temp=Bucket[i];
		while(temp!=NULL){
			if(temp->key==key){
				return &(temp->value);
			}
			temp=temp->next;
		}
		return NULL;
	}

	T& operator[](string key){  	  //operator overloading for eg. h["Mango"]=100;
		T* temp=search(key);
		if(temp==NULL){
			T garbage;  			  //we don't know the value yet
			insert(key,garbage);
			temp=search(key);
			return *temp;
		}
		else{
			return *temp;
		}
	}

	void print(){
		for(int i=0;i<ts;i++){
			cout<<"Bucket "<<i<<"-->";
			node<T>* temp=Bucket[i];
			while(temp!=NULL){
				cout<<temp->key<<",";
				temp=temp->next;
			}
			cout<<endl;
		}
	}

	void erase(){

		//homework
	}
};

int main(){
	hashmap<int> h;
	h.insert("Mango",100);
	h.insert("Guava",50);
	h.insert("Papaya",60);
	h["Kiwi"]=30;
	//all three functions through operation overloading
	h["Apple"]=20;     //inseartion
	cout<<h["Apple"]<<endl;  //searching

	int *temp=h.search("Mango");
	cout<<*temp<<endl;
	h["Apple"]=200;    //updation
	h.print();
	cout<<endl;
	return 0;
}