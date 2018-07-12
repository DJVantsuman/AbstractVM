#ifndef STACKVM_H
#define STACKVM_H


class StackVM
{
private:
    int size;
public:
    StackVM();
    StackVM(StackVM const &src);
    ~StackVM();

    StackVM &operator=(StackVM const &rhs);
};

#endif // STACKVM_H
