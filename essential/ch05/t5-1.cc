class Stack
{
public:
    virtual bool pop() = 0;
    virtual bool push() = 0;
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual int peek() const = 0;
    virtual void print() const = 0;
};

class LIFO_Stack : public Stack
{
public:
    bool pop();
    bool push();
    int size() const;
    bool empty() const;
    bool full() const;
    int peek() const;
    void print() const;
};