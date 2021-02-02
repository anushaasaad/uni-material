#include<iostream>
#include<conio.h>
using namespace std;

class Gift
{
	private:
	string catID;
	int price;
	bool taxAp;
	int tax;
	protected:
	static int total_tax;	
	static int stock;
	static int revenue;
	static int f_stock;
	static int p_stock;
	static int c_stock;
	public:
	Gift(string catID,int price,bool taxAp)
	{
		this->catID=catID;
		this->price=price;
		this->taxAp=taxAp;
	}
	Gift()
	{
	}
	virtual void bill()=0;
	void set_catID(string x)
	{
		catID=x;
	}
	string get_catID()
	{
		return catID;
	}
	int get_price()
	{
		return price;
	}
	void set_taxAp(bool x)
	{
		taxAp=x;
	}
	bool get_taxAp()
	{
		return taxAp;
	}
	void set_tax(int x)
	{
		tax=x;
	}
	int get_tax()
	{
		return tax;
	}
	void set_revenue(int x)
	{
		revenue=x;
	}
	static int get_revenue()
	{
		return revenue;
	}
	void set_stock(int x)
	{
		stock=x;
	}
	static int get_stock()
	{
		return stock;
	}
	static int get_f_stock()
	{
		return f_stock;
	}
	static int get_p_stock()
	{
		return p_stock;
	}
	static int get_c_stock()
	{
		return c_stock;
	}
	static int get_total_tax()
	{
		return total_tax;
	}
	static void set_f_stock(int x)
	{
		f_stock=x;
	}
	static void set_p_stock(int x)
	{
		p_stock=x;
	}
	static void set_c_stock(int x)
	{
		c_stock=x;
	}
	virtual void calc_tax()=0;
};
int Gift::revenue=0;
int Gift::stock=300;
int Gift::f_stock=100;
int Gift::p_stock=100;
int Gift::c_stock=100;
int Gift::total_tax=0;
class Flowers: public Gift
{
	private:
	string floral;
	int qt;
	public:
	Flowers(string catID,int price,bool taxAp,string floral,int qt): Gift(catID,price,taxAp)
	{
		this->floral=floral;
		this->qt=qt;
	}
	void calc_tax()
	{
		set_tax(0);
	}
	Flowers(){}
	Flowers(const Flowers& obj)
	{
	}
	void set_floral(string x)
	{
		floral=x;
	}
	string get_floral()
	{
		return floral;
	}
	void bill()
	{
		cout<<"You bought "<<qt<<" "<<floral<<" and your bill is "<<qt*50<<endl;
	}
	void f_stock_update()
	{
		f_stock-=qt;
		stock=f_stock+c_stock+p_stock;
	}
	void f_revenue_update()
	{
		revenue=revenue+(get_price()*qt);
	}
};
class Perfume: public Gift
{
	private:
	string brand;
	int qt;
	public:
	Perfume(string catID,int price,bool taxAp,string brand,int qt):Gift(catID,price,taxAp)
	{
		this->brand=brand;
		this->qt=qt;
	}
	Perfume(){}
	void set_brand(string x)
	{
		brand=x;
	}
	string get_brand()
	{
		return brand;
	}
	void bill()
	{
		cout<<"You bought "<<qt<<" "<<brand<<" and your bill is "<<(get_price())*qt<<endl;
	}
	void p_stock_update()
	{
		p_stock-=qt;
		stock=p_stock+f_stock+c_stock;
	}
	void p_revenue_update()
	{
		revenue=revenue+(get_price()*qt);
	}
	void calc_tax()
	{
		int ptax=(get_price())*0.07;
		set_tax(ptax);
		total_tax=total_tax+(ptax*qt);
	}
};
class Cake: public Gift
{
	private:
	int weight;
	string message;
	public:
	Cake(string catID,int price,bool taxAp,int weight,string message):Gift(catID,price,taxAp)
	{
		this->weight=weight;
		this->message=message;
	}
	Cake(){}
	void set_weight(int x)
	{
		weight=x;
	}
	int get_weight()
	{
		return weight;
	}
	void set_message(string x)
	{
		message=x;
	}
	string get_message()
	{
		return message;
	}
	void c_stock_update()
	{
		c_stock-=weight;
		stock=c_stock+p_stock+f_stock;
	}
	void c_revenue_update()
	{
		revenue=revenue+(get_price());
	}
	void calc_tax()
	{
		int ptax=(get_price())*0.04;
		set_tax(ptax);
		total_tax+=(ptax);
	}
	void bill()
	{
		cout<<"You bought "<<weight<<" "<<"pounds of chocolate cake"<<" and your bill is "<<(get_price())<<endl;
	}
};
class HappyBundle: public Cake, public Perfume, public Flowers
{
	
	public:
	HappyBundle()
	{
	}
};
class NineTails
{
	private:
	string contact,address,email;
	public:
	NineTails(string contact,string address,string email)
	{
		this->contact=contact;
		this->address=address;
		this->email=email;
	}
	NineTails()
	{
		contact="0800-80800";
		address="Street-17, Blenheim Road, West London";
		email="ninetails@corporate.uk";
	}
	int getRevenue()
	{
		return Gift::get_revenue();
	}
	int getTax()
	{
		return Gift::get_total_tax();
	}
	void set_contact(string x)
	{
		contact=x;
	}
	string get_contact()
	{
		return contact;
	}
	void set_address(string x)
	{
		address=x;
	}
	string get_address()
	{
		return address;
	}
	void set_email(string x)
	{
		email=x;
	}
	string get_email()
	{
		return email;
	}
	friend class TaxDept;
};
class TaxDept
{
	NineTails obj;
	public:
	TaxDept(){}
	void show_Tax_and_Revenue()
	{
		cout<<"the total revenue generated at NINE-TAILS is "<<obj.getRevenue()<<" rupees and so it is liable to pay "<<obj.getTax()<<" rupees as tax\n\n";
	}
	
};
int main()
{
	A:
	int choice;
	string catID;
	cout<<"press 1) to buy\n2)to check tax\n3)to check stock\n4)to check revenue\n5)exit\n\n";
	cin>>choice;
	if(choice==1)
	{
		int choice1;
		cout<<"press 1)to buy flowers\n2)perfume\n3)chocolate cake\n\n";
		cin>>choice1;
		if(choice1==1)
		{
			string catid,fname;
			int qt;
			cout<<"Enter the category ID, name of flower and the quantity\n";
			cin>>catid>>fname>>qt;
			Gift* flower= new Flowers(catid,50,0,fname,qt);
			flower->calc_tax();
			static_cast<Flowers*>(flower)->f_stock_update();
			static_cast<Flowers*>(flower)->f_revenue_update();
			flower->bill();
			goto A;
		}
		if(choice1==2)
		{
			string catid,pname;
			int qt;
			cout<<"Enter the category ID, name of perfume and the quantity\n";
			cin>>catid>>pname>>qt;
			if(pname=="gucci"||pname=="GUCCI")
			{
				Gift* perf=new Perfume(catid,1200,1,pname,qt);
				perf->calc_tax();
				static_cast<Perfume*>(perf)->p_stock_update();
				static_cast<Perfume*>(perf)->p_revenue_update();
				perf->bill();
				goto A;
			}
			if(pname=="versace"||pname=="VERSACE")
			{
				Gift* perf=new Perfume(catid,1100,1,pname,qt);
				perf->calc_tax();
				static_cast<Perfume*>(perf)->p_stock_update();
				static_cast<Perfume*>(perf)->p_revenue_update();
				perf->bill();
				goto A;
			}
			if(pname=="chanel"||pname=="CHANEL")
			{
				Gift* perf=new Perfume(catid,950,1,pname,qt);
				perf->calc_tax();
				static_cast<Perfume*>(perf)->p_stock_update();
				static_cast<Perfume*>(perf)->p_revenue_update();
				perf->bill();
				goto A;
			}
		}
		if(choice1==3)
		{
			int wght;
			string catid,msg;
			cout<<"Enter the category ID, weight of the cake and the message that you want written on it respectively\n";
			cin>>catid>>wght>>msg;
			Gift* ck= new Cake(catid,700*wght,1,wght,msg);
			ck->calc_tax();
			static_cast<Cake*>(ck)->c_stock_update();
			static_cast<Cake*>(ck)->c_revenue_update();
			ck->bill();
			goto A;
		}
	}
	if(choice==2)
	{
		TaxDept obj;
		obj.show_Tax_and_Revenue();
		goto A;
	}
	if(choice==3)
	{
		cout<<"Remaining cake stock "<<Gift::get_c_stock()<<" pounds"<<endl;
		cout<<"Remaining flower stock "<<Gift::get_f_stock()<<" flowers"<<endl;
		cout<<"Remaining perfume stock "<<Gift::get_p_stock()<<" perfumes"<<endl;
		cout<<"Total remaining stock "<<Gift::get_stock()<<" items"<<endl;
		goto A;
	}
	if(choice==4)
	{
		cout<<"Total revenue generated"<<Gift::get_revenue()<<" Rupees"<<endl;
		goto A;
	}
	if(choice==5)
	{
		return 0;
	}
}
