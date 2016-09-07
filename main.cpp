#include <QCoreApplication>

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <memory>

//Test functions
class B;

class A
{
public:
	A()
	{
	}

	~A()
	{
		std::cout<<"Destructor of A!"<<std::endl;
	}

	void setB(B &b)
	{
		this->b = boost::shared_ptr<B>(&b);
	}

	boost::shared_ptr<B> b;
};

class B
{
public:
	B(const A& a)//constructor
	{
		std::cout<<"ctor called!"<<std::endl;
	}

	B& operator =(const A& a){std::cout<<"assignment operator called!"<<std::endl;return *this;}//assignment operator

	operator A(){std::cout<<"typecast operator called!"<<std::endl;return A();}//typecast-operator

	~B()
	{
		std::cout<<"Destructor of B!"<<std::endl;
	}

	void setA(A &a)
	{
		this->a = boost::shared_ptr<A>(&a);
	}

	boost::shared_ptr<A> a;
};


int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	A foo;
	B bar(foo);
	bar = foo;
	foo = bar;

	return 0;
}

















