#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class ninetails{
	string contactno;
	string address;
	string email;
	public:
		friend class taxation_dept;
		
		ninetails(string contactno,string address,string email){
			this->address=address;
			this->contactno=contactno;
			this->email=email;
		}
		string get_contactno(){
			return contactno;
		}
		string get_address(){
			return address;
		}
		string get_email(){
			return email;
		}
		
};

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
	int get_totaltax(){
		return totaltax;
	}
	int get_taxcalculation(){
		return tax;
	}
	void tax_applicable(string t){
		taxApplicable=t;
		if(taxApplicable=="true"){
			
		}else{
			cout<<"---tax isn't applicable...enjoy ..save your money.. bhangra pa---'" <<endl;
		}
	}
	void cal_revenue(int quantity){
		revenue = revenue+get_price()*quantity;
	} 
	int get_revenue(){
		return revenue;
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

int gift :: stock=0; 
int gift :: fl=50; 
int gift:: pf=50; 
int gift :: ck=50; 
int gift :: revenue=0;
int gift :: totaltax=0;  

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
    void get_remainingstock(int quantity){
    	fl-=quantity;
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
        void get_remainingstock(int quantity){
    	     pf-=quantity;
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
        void get_remainingstock(int quantity){
    	    ck-=quantity;
	} 

};
class taxation_dept{

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
		    cout<<"enter type of flower you want: (Rose,Daisy,tulip): " ;
            cin>>type;
            cout<<"Enter Brand you want:(GUCCI, VERSACE or CHANEL)" ;
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
        	cout<<"how many chocolate cakes you want:" <<endl;
        	cin>>q;
            if(brand=="gucci" || brand=="versace" || brand=="chanel"){
            	cout<<"enter the quantity of perfume: " <<endl;
                cin>>q;
            	perfume p(brand,catID2);
            	p.set_catID(catID2);
            	p.set_type(brand);
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
			cout<<catID1 <<"has greater profit than " <<catID2 <<endl;
		}else{
			cout<<catID2 <<"has greater profit than " <<catID1 <<endl;
		}
		
	}
};

int main()
{
    cout<<"1)Flowers(fl))\n2)Perfumes(pf)\n3)Chocolate Cake(ck)\n4)Happy Bundle(hb)\n5)Taxation Deaprtment Details" <<endl;
    int choice,q;
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
            	f.tax_applicable("false");
                f.bill(q);
                flower f1(f);
                f.cal_revenue(q);
                system("cls");
                f.print();
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
            	g->tax_applicable("true");
            	g->tax_calculation(q,0.07);
            	g->total_tax();
                g->bill(q);
                g->set_tax(7);
                g->cal_revenue(q);
                system("cls");
                g->print();
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
        	c.tax_applicable("true");
        	c.tax_calculation(q, 0.04);
        	c.total_tax();
        	c.set_tax(4);
        	c.bill(q);
        	c.cal_revenue(q);
        	system("cls");
        	c.print();
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
				    happy_bundle f1("fl","pf");
				    cout<<"For second instance. " <<endl;
				    happy_bundle p2("pf","ck");
	    			f1>p2;
				}
				if(x==2){
					happy_bundle p2("pf","ck");
					cout<<"For second instance. " <<endl;
					happy_bundle c3("ck","fl");
					p2>c3;
				}
				if(x==3){
					happy_bundle c3("ck","fl");
					cout<<"For second instance. " <<endl;
					happy_bundle f1("fl","pf");
					c3>f1;
				}
	    		
			}
			 
		}	          
}
