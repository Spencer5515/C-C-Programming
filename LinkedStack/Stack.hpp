#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class Stack {
    protected:
        // the current number of elements in the stack
        int length;

    public:
        // default constructor
        Stack() { }

        // destructor
        virtual ~Stack() { }

        // remove all elements in the stack
        virtual void clear() = 0;

        // return the current length of the stack
        virtual int getLength() const = 0;

        // determine if the stack currently empty
        virtual bool isEmpty() const = 0;

        // remove the top element from the stack
        virtual void pop() = 0;

        // add the argument to the top of the stack
        virtual void push(const T&) = 0;

        // return the element at the top of the stack
        virtual T top() const = 0;
};

#endif
