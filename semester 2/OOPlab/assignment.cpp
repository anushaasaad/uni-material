#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class gift{
	private:
    string catID ;
    string taxApplicable;
    int tax;
    int price; 
	string type; 
    protected:
    int t;
    float rate; 
    static int stock; 
    static int fl;
    static int pf; 
    static int ck; 
    static int totaltax;
    static int revenue;  
    public: 
    gift(){
	}
	virtual void bill(int qauntyity)=0;
	
	void set_price(int price){
		this->price=price;
	}
	int get_price(){
		return price;
	}
	void set_catID(string catID){
		this->catID=catID;
	}
	void tax_calculation(int quantity, float rate){
		tax=quantity*get_price()*rate;
	}
	void total_tax(){
		totaltax+=tax;
	}
	static int get_totaltax(){
		return totaltax;
	}
	static void print_totaltax(){
		cout<<"Total Tax: " <<get_totaltax() <<endl;
	}
	int get_taxcalculation(){
		return tax;
	}
	void tax_applicable(string t){
		taxApplicable=t;
		if(taxApplicable=="true"){
			cout<<"Tax Applicable." <<endl;
		}else{
			cout<<"Tax isn't applicable'" <<endl;
		}
	}
	void cal_revenue(int quantity){
		revenue = revenue+get_price()*quantity;
	} 
	static int get_revenue(){
		return revenue;
	}
	static void print_revenue(){
		cout<<"Revenue: " <<get_revenue() <<endl;
	}
	void set_catID(int catID){
		this->catID=catID;
	}
	string get_catID(){
		return catID;
	}
	void set_type(string type){
		this->type=type;
	}
	void set_tax(int t){
		this->t=t;
	}
	int get_tax(){
		return t;
	}
	
	void print(){
		cout<<"The gift Category ID: " <<get_catID() <<endl;
		cout<<"The Gift Selected: " <<type <<endl;
		cout<<"The orignal price of item: " <<get_price() <<endl;
		cout<<"The Tax applicable: " <<get_tax() <<"%"<<endl;
		cout<<"The price after Applying Tax: " <<get_taxcalculation() <<endl;
	}
	
};

int gift::stock=0; 
int gift::fl=50; 
int gift::pf=50; 
int gift::ck=50; 
int gift::revenue=0;
int gift::totaltax=0;  

class flower: public gift{
	protected:
    string floraltype;
    public:
    flower(){
	}
    flower(string floraltype,string catID){
    	this->floraltype=floraltype;
    	set_catID(catID);
        set_price(50);
	}
	
    flower(const flower &f2){
   	   floraltype=f2.floraltype;
   	   cout<<"Flower chooosed: " <<f2.floraltype <<". " <<endl; //to show that the the task(copy constructor) given in part g.
   }
    void bill(int quantity){
  	cout<<"Total price of flowers:: " <<get_price()*quantity <<endl;
  
  }	
    void remainingstock(int quantity){
    	fl-=quantity;
	}
	int get_remainingstock(){
		return fl;
	}
	void set_remainingstock(){
		cout<<"remaining stock: " <<get_remainingstock() <<endl;
		
	}
    
};
class perfume: public gift{
	protected:
		string brand;
	public:
		perfume(){
		}
		perfume(string brand,string catID){
			set_catID(catID);
			this->brand=brand;
			if(brand=="gucci"){
				set_price(1200);
			}else if(brand=="versace"){
				set_price(1100);
			}else if(brand=="chanel"){
				set_price(950);
			}
    }
        
	    void bill(int quantity){
  	         cout<<"Total price of perfume:: " <<get_price()*quantity <<endl;
  
  }	
        void remainingstock(int quantity){
    	     pf-=quantity;
	}
	    int get_remainingstock(){
		return pf;
	}
	void set_remainingstock(){
		cout<<"remaining stock: " <<get_remainingstock() <<endl;
		
	}
    
};
class chocolate_cake: public gift{
    int weight;
    string msgoncake;
    public:
    	chocolate_cake(){
		}
		chocolate_cake(int weight, string msgoncake, string id){
			this->msgoncake=msgoncake;
			this->weight=weight;
			set_price(700);
		}
		void bill(int quantity){
  	        cout<<"Total price of cake:: " <<get_price()*weight*quantity <<endl;
  
  }	
        void remainingstock(int quantity){
    	    ck-=quantity;
	} 
	   int get_remainingstock(){
		return ck;
	}
    void set_remainingstock(){
		cout<<"remaining stock: " <<get_remainingstock() <<endl;
		
	}

};
class happy_bundle: public flower, public perfume ,public chocolate_cake{
	protected:
		string catID1,catID2,ty;
		int price,q;
	public:
	happy_bundle(string cID1, string cID2){
		this->catID1=cID1;
		this->catID2=cID2;
	    if(catID1=="fl" && catID2=="pf"){
		    string type;
		    int q;
		    perfume p;
		    flower f2;
            cout<<"Enter Brand of perfume:(GUCCI, VERSACE or CHANEL)" ;
            cin>>brand;
            if(brand=="gucci" || brand=="versace" || brand=="chanel"){
            	cout<<"enter the quantity of perfume: " <<endl;
                cin>>q;
            	perfume p(brand,catID2);
            	p.set_catID(catID2);
            	p.set_type(brand);
			}else{
				cout<<"no valid input" <<endl;
			}
			cout<<"enter type of flower: (Rose,Daisy,tulip): " ;
            cin>>type;
            if(type=="rose" || type=="daisy" || type=="tulip"){
            	cout<<"enter the quantity of flowers: " <<endl;
                cin>>q;
            	flower f2(type,catID1);
            	f2.set_type(type);
            	f2.set_catID(catID1);
                system("cls");
	}
       price= p.get_price()+f2.get_price();
}

	if(catID1=="pf" && catID2 =="ck"){
		    perfume p;		
		    cout<<"Enter Brand you want:(GUCCI, VERSACE or CHANEL)" ;
            cin>>brand;
            if(brand=="gucci" || brand=="versace" || brand=="chanel"){
            	cout<<"enter the quantity of perfume: " <<endl;
                cin>>q;
            	perfume p(brand,catID2);
            	p.set_catID(catID2);
            	p.set_type(brand);
            	cout<<"how many chocolate cakes you want:" <<endl;
        	    cin>>q;
        	    chocolate_cake c(5,"happybirthday",catID2);
        	    c.set_catID(catID2);
        	   c.set_type("chocolate-cake");
        	   price=p.get_price() + c.get_price();
        }
    }else
	
   	if(catID1=="ck" && catID2=="fl"){
        	cout<<"how many chocolate cakes you want:" <<endl;
        	cin>>q; 
		    chocolate_cake c(5,"happybirthday",catID2);
        	c.set_catID(catID2);
        	c.set_type("chocolate-cake");
        	 cout<<"enter type of flower you want: (Rose,Daisy,tulip): " ;
            cin>>ty;
        	if(ty=="rose" || ty=="daisy" || ty=="tulip"){
            	cout<<"enter the quantity of flowers: " <<endl;
                cin>>q;
            	flower f2(ty,catID1);
            	f2.set_type(ty);
            	f2.set_catID(catID1);
                
	    }  
	}
}
	void operator > (happy_bundle& h)
	{
		if(price>h.price){
			cout<<catID1 <<" has greater profit than " <<catID2 <<endl;
		}else{
			cout<<catID2 <<" has greater profit than " <<catID1 <<endl;
		}
		
	}
};
class ninetails{
	string contactno;
	string address;
	string email;
	public:
	    ninetails(){
		}
		ninetails(string contactno,string address,string email){
			this->address=address;
			this->contactno=contactno;
			this->email=email;
		}
		void ShowRevenue(){
            gift::print_revenue();
        }
        void ShowTax(){
            gift::print_totaltax();
    }
    friend class taxation_dept;	
		
};

class taxation_dept{
	ninetails n; 
    public:
    taxation_dept(){
	}
    void Show() 
    {
    	n.ShowRevenue();
    	n.ShowTax();
    }

};

int main()
{
	int choice,q;
	string ad,e,cno;
	cout << "Enter your contact number: " << endl;  
    cin>> cno; 
    cout << "Enter your address: " << endl; 
    cin>> ad; 
    cout << "Enter your email address: " << endl; 
    cin>> e;
    ninetails n(cno,ad,e);
	system("cls");
	do{
    cout<<"1)Flowers(fl))\n2)Perfumes(pf)\n3)Chocolate Cake(ck)\n4)Happy Bundle(hb)\n5)Taxation Deaprtment Details\n6)exit." <<endl;
    cout<<"enter your choice: " <<endl;
    cin>>choice;
        if(choice==1){
	
            string type,id; //type of flowers
            system("cls");
            cout<<"**FLOWERS**" <<endl;
            cout<<"enter the ID:" <<endl;
            cin>>id;
            cout<<"enter type of flower you want: (Rose,Daisy,tulip): " ;
            cin>>type;
            if(type=="rose" || type=="daisy" || type=="tulip"){
            	cout<<"enter the quantity of flowers: " <<endl;
                cin>>q;
            	flower f(type,id);
            	f.set_type(type);
            	f.set_catID(id);
                flower f1(f);
                f.cal_revenue(q);
                f.remainingstock(q);
                system("cls");
                f.print();
                f.set_remainingstock();
               	f.tax_applicable("false");
                f.bill(q);
                f.print_revenue();
                
			}else{
				cout<<"no valid input" <<endl;
			}
  }
        if(choice==2){
            string brand,id;
            system("cls");
			int q;//brand of perfume
            cout<<"**PERFUMES**" <<endl ;
            cout<<"enter the ID:" <<endl;
            cin>>id;
            cout<<"Enter Brand you want:(GUCCI, VERSACE or CHANEL)" ;
            cin>>brand;
            if(brand=="gucci" || brand=="versace" || brand=="chanel" && id=="pf"){
            	cout<<"enter the quantity of perfume: " <<endl;
                cin>>q;
            	gift* g=new perfume (brand,id);
            	g->set_catID(id);
            	g->set_type(brand);
            	g->tax_calculation(q,0.07);
            	g->total_tax();
                g->set_tax(7);
                g->cal_revenue(q);
                system("cls");
                g->print();
                g->bill(q);
            	g->tax_applicable("true");
                g->print_revenue();
                
			}else{
				cout<<"no valid input" <<endl;
			}
  }
        if(choice==3){
        	int w,q;
        	string msg,id;
        	system("cls");
        	cout<<"enter the ID:" <<endl;
            cin>>id;
            if(id=="ck"){
			
        	cout<<"enter the weight of cake you want:(pounds)" <<endl;
        	cin>>w;
        	cout<<"enter the msg on cake you want:" <<endl;
        	cin>>msg;
        	cout<<"how many chocolate cakes you want:" <<endl;
        	cin>>q;
        	chocolate_cake c(w,msg,id);
        	c.set_catID(id);
        	c.set_type("chocolate-cake");
        	c.tax_calculation(q, 0.04);
        	c.total_tax();
        	c.set_tax(4);
        	c.cal_revenue(q);
        	c.remainingstock(q);
        	system("cls");
        	c.print();
        	c.set_remainingstock();
        	c.bill(q);
            c.tax_applicable("true");
        	c.print_revenue();
        }else{
        	cout<<"invalid input" <<endl;
		}
	}
	    if(choice==4){
	    	string id;
	    	cout<<"enter ID: " <<endl;
	    	cin>>id;
	    	if(id=="hb"){
	    		system("cls");
	    		cout<<"1) Comparing profit of Flowers and Perfume." <<endl;
	    		cout<<"2) Comparing profit of Perfume and Chocolate Cake." <<endl;
	    		cout<<"3) Comparing profit of Chocolate Cake and Flowers." <<endl;
	    		int x;
	    		cout<<"enter choice: " <<endl;
	    		cin>>x;
	    		if(x==1){
	    			system("cls");
	    			cout<<"*FLOWERS AND PERFUME*" <<endl;
				    happy_bundle f1("fl","pf");
				    cout<<"For second instance. " <<endl;
				    cout<<"*PERFUME AND CHOCOLATE CAKE*" <<endl;
				    happy_bundle p2("pf","ck");
	    			f1>p2;
				}else
				if(x==2){
					system("cls");
					cout<<"*PERFUME AND CHOCOLATE CAKE*" <<endl;
					happy_bundle p2("pf","ck");
					cout<<"*CHOCOLATE CAKE AND FLOWER*" <<endl;
					cout<<"For second instance. " <<endl;
					happy_bundle c3("ck","fl");
					p2>c3;
				}else
				if(x==3){
					system("cls");
					cout<<"*CHOCOLATE CAKE AND FLOWER*" <<endl;
					happy_bundle c3("ck","fl");
					cout<<"For second instance. " <<endl;
					cout<<"*FLOWERS AND PERFUME*" <<endl;
					happy_bundle f1("fl","pf");
					c3>f1;
				}
	    		
			}else{
				cout<<"invalid input" <<endl;
			}
			 
		}
		if(choice==5){
			cout<<"*Taxation department*" <<endl;
			taxation_dept t;
			t.Show();
		}
		
		if(choice==6){
			break;
		}   
		cout<<"\n\t*****\n"; 
    }while(choice<7);
}
