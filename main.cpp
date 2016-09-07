#include <QCoreApplication>

#include <iostream>
#include <boost/shared_ptr.hpp>

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
	B()
	{
	}

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

	A a;
	B b;

	a.setB(b);
	b.setA(a);

	return 0;
}
