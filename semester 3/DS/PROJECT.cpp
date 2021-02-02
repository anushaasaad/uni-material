#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
char ch[4]={'A','B','C','T'};
int A=0,B=1,C=2,Total=3,Y2019=0,Y2020=1;
int Health=0,Home=1,Sports=2,Fashion=3,Food=4,Electronic=5;
string Type[]={"Health","Home","Sports","Fashion","Food","Electronic"}; 
float BranchSale_Year[4][2];
int Quantity_Year[3][2];
float Mean_Year[3][2];
float BranchSale_Product[4][6][2];
int Quantity_Product[4][6][2];
int GraphA[10][20];
int Count[3]={0,0,0};
float gradient[3]={0,0,0};
int rat=0;
int x=0;
class Customer
{
    char branch;
    string type;
    float price;
    
    int quantity;
    float total;
    int year;
    float rating;
    Customer * next;
    friend class Data;
};
class Data
{
    
    Customer *head,*tail;
    // void Graph(int price)
    // {
    //     if(Count[0]%10==1)
    //     {
    //         GraphA[(rat/10)%10][x]=1;
    //     }
    //     rat=rat+price;
    //     x++;
    // }
    public:
    Data(){head=NULL;tail=NULL;}
    void ReadData()
    {
        ifstream is("C://Users//Sameer//Desktop//university//SEM 3//DS//Project//DataSet.txt");
        if(is)
        {
            for(int i=0;i<600;i++)
            {
                Customer *temp = new Customer;		
                is>>temp->branch;
                is>>temp->type;
                is>>temp->price;
                is>>temp->quantity;
                is>>temp->total;
                is>>temp->year;
                is>>temp->rating;
                temp->next=NULL;
   
                if(temp->branch=='A')
                {Count[A]++;
                for(int k=0;k<6;k++)
                    {if(temp->type==Type[k])
                        {if(temp->year==2019)
                            {Quantity_Year[A][Y2019]++;
                            Mean_Year[A][Y2019]=BranchSale_Year[A][Y2019]/Count[A];
                            Quantity_Product[A][k][Y2019]=Quantity_Product[A][k][Y2019]+temp->quantity;
                            BranchSale_Product[A][k][Y2019]=BranchSale_Product[A][k][Y2019]+temp->total;
                            BranchSale_Product[Total][k][Y2019]=BranchSale_Product[Total][k][Y2019]+temp->total;
                            BranchSale_Year[A][Y2019]=BranchSale_Year[A][Y2019]+temp->total;
                            BranchSale_Year[Total][Y2019]=BranchSale_Year[Total][Y2019]+temp->total;}
                            else
                            {Quantity_Year[A][Y2020]++;
                            Mean_Year[A][Y2020]=BranchSale_Year[A][Y2020]/Count[A];
                            Quantity_Product[A][k][Y2020]=Quantity_Product[A][k][Y2020]+temp->quantity;
                            BranchSale_Product[A][k][Y2020]=BranchSale_Product[A][k][Y2020]+temp->total;
                            BranchSale_Product[Total][k][Y2020]=BranchSale_Product[Total][k][Y2020]+temp->total;
                            BranchSale_Year[A][Y2020]=BranchSale_Year[A][Y2020]+temp->total;
                            BranchSale_Year[Total][Y2020]=BranchSale_Year[Total][Y2020]+temp->total;}
                        }
                    }
                //  Graph((Mean_Year[A][Y2019]+Mean_Year[A][Y2020])/2);
                }            
                if(temp->branch=='B')
                {Count[B]++;
                for(int k=0;k<6;k++)
                    {if(temp->type==Type[k])
                        {if(temp->year==2019)
                            {Quantity_Year[B][Y2019]++;
                            Mean_Year[B][Y2019]=BranchSale_Year[B][Y2019]/Quantity_Year[B][Y2019];
                            Quantity_Product[B][k][Y2019]=Quantity_Product[B][k][Y2019]+temp->quantity;
                            BranchSale_Product[B][k][Y2019]=BranchSale_Product[B][k][Y2019]+temp->total;
                            BranchSale_Product[Total][k][Y2019]=BranchSale_Product[Total][k][Y2019]+temp->total;
                            BranchSale_Year[B][Y2019]=BranchSale_Year[B][Y2019]+temp->total;
                            BranchSale_Year[Total][Y2019]=BranchSale_Year[Total][Y2019]+temp->total;}
                            else
                            {Quantity_Year[B][Y2020]++;
                            Mean_Year[B][Y2020]=BranchSale_Year[B][Y2020]/Quantity_Year[B][Y2020];
                            Quantity_Product[B][k][Y2020]=Quantity_Product[B][k][Y2020]+temp->quantity;
                            BranchSale_Product[B][k][Y2020]=BranchSale_Product[B][k][Y2020]+temp->total;
                            BranchSale_Product[Total][k][Y2020]=BranchSale_Product[Total][k][Y2020]+temp->total;
                            BranchSale_Year[B][Y2020]=BranchSale_Year[B][Y2020]+temp->total;
                            BranchSale_Year[Total][Y2020]=BranchSale_Year[Total][Y2020]+temp->total;}
                        }
                    }
                }
                if(temp->branch=='C')
                {Count[C]++;
                for(int k=0;k<6;k++)
                    {if(temp->type==Type[k])
                        {if(temp->year==2019)
                            {Quantity_Year[C][Y2019]++;
                            Mean_Year[C][Y2019]=BranchSale_Year[C][Y2019]/Quantity_Year[C][Y2019];
                            Quantity_Product[C][k][Y2019]=Quantity_Product[C][k][Y2019]+temp->quantity;
                            BranchSale_Product[C][k][Y2019]=BranchSale_Product[C][k][Y2019]+temp->total;
                            BranchSale_Product[Total][k][Y2019]=BranchSale_Product[Total][k][Y2019]+temp->total;
                            BranchSale_Year[C][Y2019]=BranchSale_Year[C][Y2019]+temp->total;
                            BranchSale_Year[Total][Y2019]=BranchSale_Year[Total][Y2019]+temp->total;}
                            else
                            {Quantity_Year[C][Y2020]++;
                            Mean_Year[C][Y2020]=BranchSale_Year[C][Y2020]/Quantity_Year[C][Y2020];
                            Quantity_Product[C][k][Y2020]=Quantity_Product[C][k][Y2020]+temp->quantity;
                            BranchSale_Product[C][k][Y2020]=BranchSale_Product[C][k][Y2020]+temp->total;
                            BranchSale_Product[Total][k][Y2020]=BranchSale_Product[Total][k][Y2020]+temp->total;
                            BranchSale_Year[C][Y2020]=BranchSale_Year[C][Y2020]+temp->total;
                            BranchSale_Year[Total][Y2020]=BranchSale_Year[Total][Y2020]+temp->total;}
                        }
                    }
                }
                if(head==NULL)
                  {head=temp;
                  tail=temp;}
                else
                  {tail->next=temp;
                  tail=tail->next;}
            }
        }
        else
        {cout<<"exit";}
    }
    void CalMean(){
        Mean_Year[A][Y2019]=BranchSale_Year[A][Y2019]/Quantity_Year[A][Y2019];
        Mean_Year[B][Y2019]=BranchSale_Year[B][Y2019]/Quantity_Year[B][Y2019];
        Mean_Year[C][Y2019]=BranchSale_Year[C][Y2019]/Quantity_Year[C][Y2019];
        Mean_Year[A][Y2020]=BranchSale_Year[A][Y2020]/Quantity_Year[A][Y2020];
        Mean_Year[B][Y2020]=BranchSale_Year[B][Y2020]/Quantity_Year[B][Y2020];
        Mean_Year[C][Y2020]=BranchSale_Year[C][Y2020]/Quantity_Year[C][Y2020];
    }
    void CalGradient()
    {
    }
    void GetGraph(float M)
    {for(float i=10;i>=-10;)
      {for(float j=-10;j<=10;)
        {
        if(j==M*i+0)
          {cout<<"#";}
        else
          {cout<<" ";}
          j=j+1;
        }
        i=i-1;
        cout<<endl;
    }}
    void DisplayData()
    {Customer *temp=head;
        while(temp!=NULL)
        {cout<<temp->branch<<"\t";
        cout<<temp->type<<"\t";
        cout<<temp->price<<"\t";
        cout<<temp->quantity<<"\t"; 
        cout<<temp->total<<"\t";
        cout<<temp->year<<"\t";
        cout<<temp->rating<<"\t";
        cout<<endl;
        temp=temp->next;}
    } 
    void Display_Branch_Sale()
    {cout<<"\n#   | 2019"<<"\t2020"<<endl;
    cout<<"------------------------"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<ch[i]<<"   |";
        for(int j=0;j<2;j++)
        {
            cout<<BranchSale_Year[i][j]<<"\t";
        }
        cout<<endl;
    }} 

    void Display_Branch_Mean()
    {cout<<"\nMEAN| 2019"<<"\t2020"<<endl;
    cout<<"------------------------"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<ch[i]<<"   |";
        for(int j=0;j<2;j++)
        {
            cout<<Mean_Year[i][j]<<"\t";
        }
        cout<<endl;
    }}

    void Display_Product_Sale()
    {
    cout<<"\n#19 |";
    for(int i=0;i<6;i++)
    {cout<<left<<setw(10)<<Type[i];}
    cout<<"\n----------------------------------------------------------------"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<ch[i]<<"   |";
        for(int j=0;j<6;j++)
        {
            cout<<left<<setw(10)<<BranchSale_Product[i][j][Y2019];
        }
        cout<<endl;
    }
    cout<<"\n#20 |";
    for(int i=0;i<6;i++)
    {cout<<left<<setw(10)<<Type[i];}
    cout<<"\n----------------------------------------------------------------"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<ch[i]<<"   |";
        for(int j=0;j<6;j++)
        {
            cout<<left<<setw(10)<<BranchSale_Product[i][j][Y2020];
        }
        cout<<endl;
    }}

    void Display_Product_Quantity()
    {cout<<"\n#19 |";
    for(int i=0;i<6;i++)
    {cout<<left<<setw(10)<<Type[i];}
    cout<<"\n----------------------------------------------------------------"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<ch[i]<<"   |";
        for(int j=0;j<6;j++)
        {
            cout<<left<<setw(10)<<Quantity_Product[i][j][Y2019];
        }
        cout<<endl;
    }
    cout<<"\n#20 |";
    for(int i=0;i<6;i++)
    {cout<<left<<setw(10)<<Type[i];}
    cout<<"\n----------------------------------------------------------------"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<ch[i]<<"   |";
        for(int j=0;j<6;j++)
        {
            cout<<left<<setw(10)<<Quantity_Product[i][j][Y2020];

        }
        cout<<endl;
    }}

    // void Display_Graph()
    // {
    //     for(int i=0;i<10;i++)
    //     {
    //         for(int j=0;j<20;j++)
    //         {
    //             if(GraphA[i][j]==1)
    //             cout<<"#";
    //             else
    //             {
    //                 cout<<" ";
    //             }   
    //         }
    //         cout<<endl;
    //     }
    // }
};
int main()
{
    Data ob;
    ob.ReadData();
    ob.CalMean();
    // ob.DisplayData(); 
    ob.Display_Branch_Sale();
    ob.Display_Product_Sale(); 
    cout<<endl;
    ob.Display_Product_Quantity();
    ob.Display_Branch_Mean();

    // ob.Display_Graph();
    gradient[A]=(Mean_Year[A][Y2020]-Mean_Year[A][Y2019])/12;
    cout<<gradient[A];
    // ob.GetGraph(gradient[A]);
    gradient[B]=(Mean_Year[B][Y2020]-Mean_Year[B][Y2019])/12;
    cout<<gradient[B];
    // ob.GetGraph(gradient[B]);
    gradient[C]=(Mean_Year[C][Y2020]-Mean_Year[C][Y2019])/12;
    cout<<gradient[C];
    // ob.GetGraph(gradient[C]);
    return 0;
}
