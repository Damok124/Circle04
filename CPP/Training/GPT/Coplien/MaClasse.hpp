#ifndef MACLASSE_HPP
#define MACLASSE_HPP

class MaClasse {
public:
    MaClasse();//obligatoire
    MaClasse(const MaClasse& other);//obligatoire
    MaClasse& operator=(const MaClasse& other);//obligatoire
    ~MaClasse();//obligatoire

private:
    int* m_data;//exemple
    int m_size;//exemple
};

#endif
