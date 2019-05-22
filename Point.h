//Reham Islam
//POINT CLASS
//Prompt the user to input the number of coordinate points to generate. Each coordinate point is a x- and y- coordinate value (ranging from 0 to 100).
//Randomly generate the given number of random points, and store the set of points in an unsorted_set.
//Display the set of points by displaying a star character in each point. For example, if the set contains five coordinate points, (0,0),(1,1),(2,2),(1,3),(0,4), then the following will be shown:

#include <iostream>
using namespace std;
#ifndef POINT_H
#define POINT_H

template <class T>
class Point{

//Comparison operator && Output operator (<<)
template <class S> 
friend	ostream & operator<<(ostream & out, const Point<S> & p);

template <class S> 
friend bool operator==(const Point<S> & one, const Point<S> & two);

template <class S> 
friend bool operator!=(const Point<S> & one, const Point<S> & two);

public:
	Point(T x=0,T y=0);

	T getX() const { return X; }
	T getY() const { return Y; } 

	
private:
	T X,Y;
	void output(ostream& output) const;
};


template <typename T>
ostream & operator<<(ostream & out, const Point<T> & p)
{       p.output(out);
        return out;
}

template <typename T>
bool operator==(const Point<T> & one, const Point<T> & two)
{       return(one.getX() == two.getX() && one.getY()== two.getY());
}


template <typename T>
bool operator!=(const Point<T> & one, const Point<T> & two)
{       return(one.getX() != two.getX() || one.getY()!= two.getY());
}

template <typename T>
Point<T>::Point(T x,T y){
             X=x;
             Y=y;
 }


template <typename T>
void Point<T>::output(ostream& output) const
{       output << "(" << X << "," << Y << ")" << endl;
} 


#endif
