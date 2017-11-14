#include <iostream>
#include <memory>
//#include <ap_error.h>


struct Wrong_size {};
struct Wrong_size_prod {};


template <typename data_type>
class Matrix {

private:
    //void check(std::size_t i, std::size_t j);
 std::size_t _row_num;
 std::size_t _col_num;
 std::size_t _size;
 std::unique_ptr<data_type[]> all_data_in_row;
 
public:

Matrix(const std::size_t row_num, const std::size_t col_num) : _row_num{row_num}, _col_num{col_num}, _size{col_num * row_num}, all_data_in_row{new data_type[_size]} {
    std::cout << "custom ctor\n";
  }
  
Matrix(const Matrix& m) : _row_num{m.row()}, _col_num{m.col()}, _size{m._size}, all_data_in_row{new data_type[_size]} {
  std::cout << "copy ctor\n";
  for (std::size_t i = 0; i < _size; ++i)
    all_data_in_row[i] = m.all_data_in_row[i];
}

data_type* operator[](const std::size_t i) noexcept {return &all_data_in_row[i * _col_num];} //no except va ovunque sotto
const data_type* operator[](const std::size_t i) const noexcept {return &all_data_in_row[i * _col_num];}

data_type& at(const std::size_t i, const std::size_t j){
    //fa il check
    return (*this)[i][j];
}

data_type& operator()(const std::size_t i, const std::size_t j){
#ifndef    NDEBUG
    return at(i, j);
#else
    return (*this)[i][j];
#endif 
}


Matrix& operator = (const Matrix& m){
        
    std::cout << "assignement\n";
    for (std::size_t i = 0; i < _size; ++i)
    all_data_in_row[i] = m.all_data_in_row[i];
}

//data_type& operator[](const std::size_t i) const noexcept {return all_data_in_row[i];} //no except va ovunque sotto
//const data_type& operator[](const std::size_t i) const {return all_data_in_row[i];}

std::size_t row() const {return _row_num;};
std::size_t col() const {return _col_num;};
std::size_t size() const {return _size;};
};

// copy ctor
//template <typename data_type>

template <typename data_type>
Matrix<data_type> operator + (const Matrix<data_type>& m1, const Matrix<data_type>& m2) {
    //un check sul size (same size)
    bool control = same_size(m1, m2);
    if (control == 0){
    throw Wrong_size {};
    }
        
    std::cout << "addition\n";
    
    Matrix<data_type> add_m{m1};
    
    for (auto i = 0; i < m1.row(); ++i){
        for(auto j = 0; j < m1.col(); ++j){
    add_m[i][j] = add_m[i][j] + m2[i][j] ;
    }
}
    return add_m;
}



template <typename data_type>
Matrix<data_type> operator * (const Matrix<data_type>& m1, const Matrix<data_type>& m2) {
    //un check sul size (same size or mxnxnxl)
    std::cout << "product\n";
    bool control = prod_size(m1, m2);
    if (control == 0){
    throw Wrong_size_prod{};
    }
    Matrix<data_type> prod_m{m1.row(),m2.col()};
    

    for (auto i = 0; i < m1.row(); ++i){
        for(auto j = 0; j < m2.col(); ++j){
            for (auto k = 0; k < m1.col(); ++k ){
            data_type mul = m1[i][k]*m2[k][j] ;
            prod_m[i][j] = prod_m[i][j] + mul; 
            //std:: cout << m1[i][k]*m2[k][j] << " ";
            
    }
    //std:: cout << prod_m[i][j] << std::endl;
}
}
    return prod_m;
}



template <typename data_type>
std::ostream& operator<<(std::ostream& os, const Matrix<data_type>& m) {
  for (auto  i = 0; i < m.row(); ++i){
      for (auto j = 0; j < m.col(); ++j){
    os << m[i][j] << " ";
 }
 os << std::endl; // va a capo
}
return os;
}


template <typename data_type>
bool same_size(const Matrix <data_type>& m1, const Matrix<data_type>& m2){
    bool control;
if (m1.row() == m2.row() && m2.col() == m1.col()){
    control=true;
    return control;
}
else{ 
    control=false;
    return control;
}

}

template <typename data_type>
bool prod_size(const Matrix <data_type>& m1, const Matrix<data_type>& m2){
    bool control;
if (m1.col() == m2.row()){
    control=true;
    return control;
}
else{ 
    control=false;
    return control;
}

}


int main (){
    try{
    Matrix <int> m{3, 3};
    for (int i = 0; i < m.row(); ++i){
        for (int j = 0; j < m.col(); ++j){
    m[i][j] = i*2;  
}
    }
    
    std::cout << m << std::endl;
    std::cout << m.row() << std::endl;
    std::cout << m.col() << std::endl;
    std::cout << m.at(1,1) << std::endl; //expected 2
    Matrix <int> m1{m};
    std::cout << m1 << std::endl;
    Matrix <int> m2{2,3};
    m2[0][0] = 1;
    m2[0][2] = 6;
    Matrix <int> m3 = m2 * m1;
    std::cout << m3 << std::endl;
    Matrix <int> m4 = m + m1;
    std::cout << m4 << std::endl;

}
catch (const Wrong_size) {
    std::cerr << "The matrices must have the same size" <<std::endl;
    return 1;
}

catch (const Wrong_size_prod) {
    std::cerr << "the columns of the first matrix must be equal to the rows of the second one" <<std::endl;
    return 1;
}
}
