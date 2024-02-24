#include<iostream>

class shape {
public:
  virtual double area() = 0;
  virtual ~shape(){}
};


class Circle : public shape {
	private:
	const double pi = 3.14;
	int a;
	public:
	Circle (int a1) {
	   a = a1;
	}
        double area () override {
	    return pi * a * a; 
	}
};

class Rectangle : public shape {
private:
    int a;
    int b;
public:
    Rectangle(int a1,int b1) {
        b = b1;
	a = a1;
    }
    double area () override{
       return a * b ;
      }
};

double foo(shape * ptr) {
	double x = ptr -> area();
	return x;
}

int main()
{
  int a;
  std::cout << "Enter the value,that we use to count shapes :" << std::endl;
  std::cin >> a;

  int b;
  std::cout << "Enter rectangle's second side :" << std::endl;
  std::cin >> b;

  shape* ptr = new Circle(a);
  std::cout << "Circle's shape is : ";
  std::cout << foo(ptr) << std::endl;

  delete ptr;
  ptr = nullptr;

  ptr = new Rectangle(a,b);
  std::cout << "Rectangle's shape is : ";
  std::cout << foo(ptr) << std::endl;

  delete ptr;
  ptr = nullptr;

  return 0;
}
