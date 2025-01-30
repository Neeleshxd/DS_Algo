#include<bits/stdc++.h>
using namespace std;
template<typename K, typename V> //template for the hashnode class 
class HashNode{
    public:
    V value;
    K key;
    HashNode(K key,V value){
        this->value=value;
        this->key=key;
    }
};

template<typename K,  typename V>
class HashMap{ //  class for hash map 
    HashNode<K,V>**arr;
    int  capacity;
    int size;
    HashNode<K,V>*dummy;

public:
    HashMap(){
        capacity=20;
        size=0;
        arr= new HashNode<K,V>*[capacity]; // assigning the size of the array 
        for(int i=0;i <capacity;i++){
            arr[i]= NULL;
            dummy = new HashNode<K,V>(-1,-1);
        }
    }

    int hashCode(K key){ // function for finding the index of the key 
        return key %capacity;
    }

    void insertNode(K key ,V value ){
        HashNode<K,V>* temp =new  HashNode<K ,V>(key,value);
        int hashIndex=hashCode(key); /// assigning the index value of the key to hash index 
        while(arr[hashIndex]!=NULL&&arr[hashIndex]->key!=key && arr[hashIndex]->key!=-1){
            hashIndex++;
            hashIndex%=capacity;
        }
    
        if(arr[hashIndex]==NULL || arr[hashIndex]->key==-1)
            size++;
        arr[hashIndex]=temp;
    }

    void display(){
        for(int i=0;i<capacity;i++){
            if(arr[i]!=NULL &&arr[i]->key!=-1){
                cout<<"key ="<<arr[i]->key
                <<" value ="
                << arr[i]->value << endl ;
            }
        }
    }
};

int main(){
    HashMap<int ,int >*h= new HashMap<int ,int>;
    h->insertNode(1,1);
    h->display();
}