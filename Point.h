//Reham Islam
//POINT CLASS

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
