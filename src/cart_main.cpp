#include<iostream>
#include<vector>
#include "datamodel.h"
using namespace std;

vector<Product> allProducts = {
	Product(1,"apple",26),
	Product(2,"mango",16),
	Product(3,"guava",36),
	Product(4,"banana",56),
	Product(5,"strawberry",29),
	Product(6,"pineapple",20)
};
Product *chooseProduct(){
	string productList;
	cout<<"Product List "<<endl;
	for(auto x: allProducts){
		productList.append(x.getDisplayName());
	}
	cout<<productList;
	cout<<"--------"<<endl;
	string choice;
	cin>>choice;
	
	for(int i=0;i<allProducts.size();i++)
	{
		if(choice == allProducts[i].getShortName()){
			return &allProducts[i];
		}
	}
	cout<<"Product is not found"<<endl;
	return NULL;
}
bool checkout(Cart &cart)
{
	if(cart.isEmpty())
	{
		return false;
	}
	int total = cart.getTotal();
	cout<<"Pay in cash"<<endl;
	int paid;
	cin>>paid;
	
	if(paid>=total)
	{
		cout<<"Change "<<paid-total<<endl;
		cout<<"Thank You for shopping";
		return true;
	}
	else
	{
		cout<<"Not enough cash";
		return false;
	}
}
int main()
{
	char action;
	Cart cart;
	while(true)
	{
		cout<<"Select an action -  (a)dd item, (v)iew cart, (c)heckout" <<endl;
		cin>> action;
		
		if(action == 'a'){
		 Product *product = chooseProduct();
		 if(product!=NULL)
		 {
		 	cout<<"Added to cart "<<product->getDisplayName();
		 	cart.addProduct(*product);
		 }
		}
		else if(action == 'v')
		{
			cout<<"-----Cart is-----"<<endl;
			cout<<cart.viewCart();
			cout<<"-----Cart end----"<<endl;
		}
		else{
			cout<<cart.viewCart();
			if(checkout(cart)){
				break;
			}
		}
}
return 0;
}