//Reham Islam
//This is driver fir point class


#include<iostream>
#include <unordered_set>
#include "Point.h"
using namespace std;

static int a = 20, b= 15;

struct hashfunc
{
	size_t operator()(const Point<int> & p) const
	{
    		return hash<int>()(p.getX()+p.getY());
  	}
};

struct hashec
{	size_t operator()(const Point<int> & p) const
	{	 return hash<int>()(a*p.getX()+b*p.getY());
	}

};



int main(){

	unordered_set<Point<int>,hashfunc> setOfPoints;
	int coordinate =0;

	do
	{	cout << "Please input the number of coordinate points to generate(0-100): ";
		cin >>coordinate;
	}while(coordinate > 100 || coordinate < 0);

	int randomX, randomY;
	const int MAX_ROW =coordinate, MAX_COL=coordinate;
	for(int i =0; i < coordinate; i++)
	{	randomX = std::rand() % (coordinate+ 1 - 0) + 0;
		randomY= std::rand() % (coordinate + 1 - 0) + 0;
		cout << "(" << randomX << "," << randomY << ")" << endl;
		Point<int> a(randomX, randomY);	
		setOfPoints.insert(a);	
	}

	//printing row numbers for the table
	
	   for (int row=0; row< MAX_ROW; row++)
		for (int col=0; col < MAX_COL; col++)
			if(col == 0)
			{	if(row < 10)
					cout << row << "  ";
				else
					cout << row << " ";
			}
	cout << endl;

	int col;
	for (int row=0; row< MAX_ROW; row++){
		for (col=0; col < MAX_COL; col++){
			 Point<int> curPoint (col, row);
        		//Checking whther point exsists in the ser
	                 if (setOfPoints.find (curPoint)!=setOfPoints.end())  
         		 {	cout <<"*" << "  ";
			 }
      			 else 
          			cout <<"   "; //display a space
			
		
		}
		if(row < 10)
                       cout << row << " ";
                else
                       cout << row; 
  	 	cout << endl; //end the line, move to next row
	}
	
	cout << "\n\n\n\n\n";

	unordered_set<Point<int>,hashec> set;
	set.rehash(20);
	unsigned nbuckets;
	int maxLenght =0;
	int minLenght = set.bucket_size(0);
	int valueX =0, valueY =0;
	unsigned size = set.size();
  	
	/*DISPLAYING*/
	cout << "There are " << size << " elements:\n";
	cout <<"Current load factor (size/bucket_count):"<<set.load_factor()<<endl;
	cout << "There are " << nbuckets << " buckets:\n";
	for (int i=0;i<20;i++)
	{	a= std::rand() % (20+ 1 - 0) + 0;
		b= std::rand() % (20+ 1 - 0) + 0;
		Point<int> z(a, b);
		
		//sum of the values
		valueX = valueX + a;
		valueY = valueY + b;
		
		set.insert(z) ;
		nbuckets = set.bucket_count();
		cout << "Bucket number " << i << " has " << set.bucket_size(i) << " elements.\n";
		if(set.bucket_size(i)>maxLenght)
			maxLenght = set.bucket_size(i);
		if(set.bucket_size(i) < minLenght)
			minLenght = set.bucket_size(i);

		
	}

	
	cout << "Average for value (X): " << valueX/20 << endl;
	cout << "Average for value (Y): " << valueY/20 << endl; 
	cout << "Maximum Lenght: " << maxLenght << endl;
	cout << "Minimum Lenght: " << minLenght << endl;	
	return 0;
}

