#include<iostream>
#include<cstdlib>
using namespace std;
class Calander_converter
{
 public:
// 31 28 31 30 31 30 31 31 30 31 30 31
//////////////////////////definition of constructors and member functions//////////////////////////////
 Calander_converter(){  }

//////////////////////////////////////////////////////////////////////////
int setLeapYearDate(int month, int day)
{
int total_days=0;
if(month==1)
{
total_days=day;
}else if(month==2)
{
total_days=31+day;
}else if(month==3)
{
total_days=60+day;
}else if(month==4)
{
total_days=91+day;
}else if(month==5)
{
total_days=121+day;
}else if(month==6)
{
total_days=152+day;
}else if(month==7)
{
total_days=182+day;
}else if(month==8)
{
total_days=213+day;
}else if(month==9)
{
total_days=244+day;
}else if(month==10)
{
total_days=274+day;
}else if(month==11)
{
total_days=305+day;
}else if(month==12)
{
total_days=335+day;
}else
{
cout<<"No such month error!"<<endl;
return 0;
}
return total_days;
}


int setYearDate(int month, int day)
{
int total_days=0;
if(month==1)
{
total_days=day;
}else if(month==2)
{
total_days=31+day;
}else if(month==3)
{
total_days=59+day;
}else if(month==4)
{
total_days=90+day;
}else if(month==5)
{
total_days=120+day;
}else if(month==6)
{
total_days=151+day;
}else if(month==7)
{
total_days=181+day;
}else if(month==8)
{
total_days=212+day;
}else if(month==9)
{
total_days=243+day;
}else if(month==10)
{
total_days=273+day;
}else if(month==11)
{
total_days=304+day;
}else if(month==12)
{
total_days=334+day;
}else
{
cout<<"No such month error!"<<endl;
return 0;
}
return total_days;
}
bool isLeapYear(int year){
	/*
	if(year%4==0 && year%100!=0)
		return true;
	if(year%100==0 && year%400==0)
		return true;
	return false;
	*/
	return (year%4)==3;
}

string converToEthiopianDate(int year, int month, int day){
	int num_days=isLeapYear(year)? setLeapYearDate(month, day):setYearDate(month, day);
	//-----num_days=isLeapYear(year)? num_days+245:num_days+244;
	int year_days=isLeapYear(year)? 366:365;
	num_days=isLeapYear(year)? num_days-11:num_days-10;
	num_days+=122; /*both leap and non leap year needs equal offset*/
	//num_days=month>=10? num_days-243:num_days+120;

	
	int eth_year=year-8;//(month>=1 &&  month<=8)? year-8: year-7;
		if(num_days>year_days){
		num_days-=year_days;
		eth_year+=1;	
		}
	
	int eth_num_days=/*365-*/num_days;
	int eth_day=eth_num_days%30!=0? eth_num_days%30: 30;
	int eth_month=eth_day!=30? eth_num_days/30+1: eth_num_days/30;
	
	cout<<"num_days = "<<num_days<<"  eth="<<eth_num_days<<"  "<<eth_month<<"/"<<eth_day<<"/"<<eth_year<<endl;
	num_days=isLeapYear(year)? num_days-12: num_days-11;
	//num_days=num_days-1;
	//int eth_month=num_days/30+1;
	//int eth_day=num_days%31;
	//cout<<"Ethiopan date: "<<eth_year<<"/"<<eth_month<<"/"<<eth_day<<endl;
	return "";//eth_year+"/"+eth_month+"/"+eth_day;
}

};
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
int main()
{
int dd,mm, yy;
Calander_converter calanderConverter;
while(true){
cout<<"Enter Month Date Year to conver to Ethiopian Date>> ";
cin>>mm>>dd>>yy;
calanderConverter.converToEthiopianDate(yy, mm,dd);
}
return 0;
}
