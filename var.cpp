#include <iostream> // namespace std;

int add(int n1, int n2);


int main(){
    std::cout<< "My name is OJ"<<std::endl;

    int age=12, height=50, password=123345;
    std::cout <<"my age is "<< age << " i am "<< height <<" feet tall " << 
    " my password is "<< password <<std::endl;

    //function to add and fin
    int num1 = 10, num2 = 20;
    int total = add(num1, num2);

    std::cout << "the total is "<< total << std::endl;
}

int add(int n1, int n2){
    int total = n1 + n2;
    return total;
}