#ifndef _HANDLE_H_
#define _HANDLE_H_

namespace ChainOfResponsibilityPattern
{

class Handle {



public:

	virtual ~Handle();


	//This first Change In New Branch
	// This is in master change
	virtual void HandleRequest() = 0;
	void SetSuccessor(Handle* succ);

	Handle* GetSuccessor();
protected:
	Handle();
	Handle(Handle* succ);
private:
	Handle* _succ;
};

class ConcreteHandleA:public Handle {
public:
	ConcreteHandleA();
	~ConcreteHandleA();
	ConcreteHandleA(Handle* succ);
	void HandleRequest();
protected:
private:
};

class ConcreteHandleB:public Handle {
public:
	ConcreteHandleB();
	~ConcreteHandleB();
	ConcreteHandleB(Handle* succ);
	void HandleRequest();
protected:
private:
};
}
#endif //~_HANDLE_H_
