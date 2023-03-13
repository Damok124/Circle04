#ifndef MACLASSE_HPP
#define MACLASSE_HPP

#include <iostream>

class MaClasse {
public:
    MaClasse();
    void (MaClasse::*getFunction(int index))();

private:
    void (MaClasse::*m_func[4])();

    void func1();
    void func2();
    void func3();
    void func4();
};

#endif // MACLASSE_HPP
