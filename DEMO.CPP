#include "conio.h"
#include"stdio.h"
#include"iostream"
#include "Btree.cpp"
#include<fstream>
#include<string>
using namespace std;
typedef struct{
string _tv;
string _el;
int dem;
} word;
string test;
word *Dictionary;
BTree<word> tree;
string NameDelete;
BTreeNode<word> *p;
ofstream myfile;
int choose;
int flagNotification=0;
int CoutWord;  
	int error;
// variables Namesearch serve function FindNode()
string NameSearch;
float t;

void pri(BTreeNode<word> *p){
	
    cout<<p->getElem().dem<<"|"<<p->getElem()._tv<<":"<<p->getElem()._el<<endl;
}


	
void SplitString (string str,int i,word Dictionary[] )
{
  
int pos = str.find("|");      
   string el = str.substr (0,pos);     
  string tv = str.substr (pos+1);    
   Dictionary[i]._el=el;
   Dictionary[i]._tv=tv;
   Dictionary[i].dem=i;
  }
  int  ReadFile(word *dictionary)
{
	
	char str[30] ="test.txt";
	
 	ifstream inFile;
	string name;
	int i=0;
	inFile.open(str);
	 while (getline( inFile, name ))  // same as: while (getline( myfile, line ).good())
      {
      string str=name;
	  SplitString(str,i,dictionary);
       	i++; 
   	}
	   inFile.close(); 
	   
	   return i;
}

int chooseDeleteCategory;
void DeleteNodeChoose(BTreeNode<word> *p){
		if(chooseDeleteCategory==1){
		if(	p->getElem()._el.compare(NameDelete)==0){
		tree.remove(p);
		cout<<"----------Delete to success-----------"<<endl;
		cout<<p->getElem()._el<<endl;
		}
		}
		else if(chooseDeleteCategory==2){	
		if(	p->getElem()._tv.compare(NameDelete)==0){
		tree.remove(p);
		cout<<"----------Delete to success-----------"<<endl;
		cout<<p->getElem()._tv<<endl;
		}
		}
		
}
//export data into file want save
void ExportDataIntoFile(BTreeNode<word> *p){
	myfile<<p->getElem().dem<<"|"<<p->getElem()._tv<<":"<<p->getElem()._el<<endl;
}
void FindNode(BTreeNode<word> *p){

	
	if(choose==1){
		if(	p->getElem()._el.compare(NameSearch)==0){
				cout<<"Node Want Search by word English!!"<<endl;
				cout<<p->getElem().dem<<":"<<p->getElem()._el<<"--"<<p->getElem()._tv<<endl;
				flagNotification=1;
			}
				
			}	
	
	else if(choose==2){
			if(	p->getElem()._tv.compare(NameSearch)==0){
				cout<<"Node Want Search by word VietNamese!!"<<endl;
				cout<<p->getElem().dem<<":"<<p->getElem()._el<<"--"<<p->getElem()._tv<<endl;
				flagNotification=1;
			}
				
			}	
	}
	void ReplaceNode(BTreeNode<word> *p){
    	int chose;
    
    	word replace;
    	
    	if(	p->getElem()._el.compare(test)==0)
		{
			cout<<p->getElem()._tv<<"<=== word old==>"<<test<<endl;
			
			cout<<"You chose change word english (input 1)--- change vietnamese(input 2)"<<endl;
			cin>>chose;
			if(chose==1){
				cout<<"Input word english you want replace"<<endl;
				cin>>replace._el;
			  	replace._tv=p->getElem()._tv;
				p->setElem(replace);
			}
			else if(chose==2){
				cout<<"Input word vietnamese you want replace"<<endl;
			      cin>>replace._tv;
			  	replace._el=p->getElem()._el;
				p->setElem(replace);
			}
			
		}
	 
}

void SystemFind(){
	cout<<"1:Find word english"<<endl;
	cout<<"2:Find word Vietnamese!!"<<endl;
	cout<<"Choose 1 of 2:";cin>>choose;
	cout<<"input string word want search!!"<<endl;
	cin>>NameSearch;
	tree.preOrder(tree.getRoot(),FindNode);
}
int ChooseReplace;
void SystemReplace(){

	cout<<"Test Replace Element!!!"<<endl;
	cout<<"Input Word English want Replace"<<endl;
	cin>>test;
	tree.preOrder(tree.getRoot(),ReplaceNode);
}
void SystemDelete(){
	cout<<"Test Delete Element!!!"<<endl;
	cout<<"Input Word "<<endl;
 	cin>>NameDelete;
	// tree.preOrder(tree.getRoot(),DeleteNodeChoose); 
	tree.preOrder(tree.getRoot(),DeleteNodeChoose);
  	tree.preOrder(tree.getRoot(),pri);	
}
void SystemInsert(BTreeNode<word> *p){
	word insert;
	int size=tree.size();
	cout<<"Enlish input!!!:"<<endl;
	cin>>insert._el;
	cout<<"Vietnamese input!!!:"<<endl;
	cin>>insert._tv;
	insert.dem=size;
	p = tree.insert(p,1,insert);
}
void SystemLoadDataToFile(){
	 CoutWord=ReadFile(Dictionary);
	// creat node root
    p = tree.insert(NULL,0, Dictionary[0]);
    //add all data into Node
	for(int i=1;i<CoutWord;i++)
	{
		if(Dictionary[i].dem<Dictionary[i+1].dem)
		{
		p = tree.insert(p,0, Dictionary[i]);
	  
		}
	else{	
		p = tree.insert(p,1, Dictionary[i]);
		}
	}
}
void menu(){
	while(1){
	int ChooseSwich;
	cout<<endl;
		cout<<"MADE IN NGUYEN MINH DUC(source code by me..)"<<endl;
		cout<<"GITHUB ME:https://github.com/ducga1998"<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"--------Dictionary----------"<<endl;
	cout << "1.Import data to file!!(Prioritize=))))"<<endl;
 	cout << "2.Show Data !!"<<endl;
 	cout <<	"3.Put data into file "<<endl;
 	cout << "4.Delete Node!!"<<endl;
 	cout << "5.Update Data in Node!!!"<<endl;
 	cout << "6.Search Node "<<endl;
 	cout<<  "7.Insert Node"<<endl;
 	cout << "8.End game=))))"<<endl;
 	cout	<<	"9.Clear Screen!!!!"<<endl;
 	cin>>ChooseSwich;
 	if(ChooseSwich==1||ChooseSwich==2||ChooseSwich==3||ChooseSwich==4||ChooseSwich==5||ChooseSwich==6||ChooseSwich==7||ChooseSwich==8||ChooseSwich==9){
	 cout<<"OK"<<endl;
	 }
	 else
	 {
	 	cout<<"You Create ERROR, Iam Stop programer!!!! :(("<<endl;
	 	cout<<"if you press the wrong button ^^ then press number 1 next programer , if NO. press 0 ........"<<endl;
	 
	 	cin>>error;
	 	if(error==1){
	 		cout<<"WELLCOME FRIEND ME"<<endl;
	 		
		 }
		 else if(error==2){
		 	cout<<"Iam sory.Goodbye :((("<<endl;
		 	return;
		 }

	 }
 
	switch (ChooseSwich)
	{
case 1: 
  	SystemLoadDataToFile();
	break;
case 2:
 	if(tree.size()>0){
 	tree.preOrder(tree.getRoot(),pri);
 	}
 	else{
 		cout<<"NO DATA"<<endl;
	}
 	
 	break;

 case 3:
 	tree.preOrder(tree.getRoot(),ExportDataIntoFile);
 	
 	break;
case 4:
	SystemDelete();
	break;
case 5:
 	SystemReplace();
 	break;
case 6:
 
	 SystemFind();
	 break;
case 7:
 	SystemInsert(p);
 	break;
case 8:
	return;
 	break;
case 9:
 	system("cls");
 	break;
default:
cout<<"Very Good"<<endl;

}
}
}
int main(){	 
	myfile.open ("example.txt");
	Dictionary=new word[1000];
  	menu();
	return 0;
}
 
