#include <iostream>
#include <sstream>



class Ulamek {
private:
    int p_;
    int q_;
    friend void operator<<(std::ostream& oss, const Ulamek&);
    friend Ulamek operator*(Ulamek& ulamek1, Ulamek& ulamek2);
    friend Ulamek operator/(Ulamek& ulamek1, Ulamek& ulamek2);
    friend Ulamek operator+(Ulamek& ulamek1, Ulamek& ulamek2);
    friend Ulamek operator-(Ulamek& ulamek1, Ulamek& ulamek2);
public:
    Ulamek(int p, int q): p_(p), q_(q) {}
    double to_decimal(){
        double temp = static_cast<double >(p_)/ static_cast<double> (q_);
        return temp;
    }
    void skroc(){
        int size = p_<=q_? p_:q_;
        for (int i = size; i != 1 ; --i) {
            if(p_%i==0 && q_%i==0)
            {
                p_/=i;
                q_/=i;
            }
        }
    }


};
const char znak = 45;

void operator<<(std::ostream& oss,const Ulamek& ulamek){

    oss<<ulamek.p_<<std::endl
        <<znak<<std::endl
        <<ulamek.q_<<std::endl<<std::endl;

}

Ulamek operator*(Ulamek& ulamek1, Ulamek& ulamek2){
    Ulamek ulamek_mul = ulamek1;
    ulamek_mul.q_*=ulamek2.q_;
    ulamek_mul.p_*=ulamek2.p_;
    return ulamek_mul;

}

Ulamek operator/(Ulamek& ulamek1, Ulamek& ulamek2){
    Ulamek ulamek_div(0,0);
    ulamek_div.q_=ulamek1.p_;
    ulamek_div.p_=ulamek1.q_;
    ulamek_div = ulamek_div* ulamek2;
    return ulamek_div;
}

Ulamek operator+(Ulamek& ulamek1, Ulamek& ulamek2){
    int temp_m = ulamek1.q_*ulamek2.q_;
    int temp_p1 = ulamek1.p_ * ulamek2.q_;
    int temp_p2 = ulamek2.p_ * ulamek1.q_;
    Ulamek ulamek_sum(temp_p1+temp_p2,temp_m);
    return ulamek_sum;

}

Ulamek operator-(Ulamek& ulamek1, Ulamek& ulamek2){
    Ulamek ulamek_minus=ulamek1+ulamek2;
    ulamek_minus.p_-=2*ulamek2.p_*ulamek1.q_;
    return ulamek_minus;

}

int main() {

    Ulamek ulamek1(2,3);
    Ulamek ulamek2(3,4);
    Ulamek ulamek3 = ulamek1*ulamek2;
    operator<<(std::cout, ulamek1);
    std::cout<<"$$$$$$$$$$$$$$$$$$$$\n\n";
    std::cout<<ulamek2;
    std::cout<<"$$$$$$$$$$$$$$$$$$$$\n\n";
    std::cout<<ulamek3;
    std::cout<<"$$$$$$$$$$$$$$$$$$$$\n\n";
    ulamek3=ulamek1/ulamek2;
    std::cout<<ulamek3;
    std::cout<<"$$$$$$$$$$$$$$$$$$$$\n\n";
    ulamek3=ulamek1+ulamek2;
    std::cout<<ulamek3;
    std::cout<<"$$$$$$$$$$$$$$$$$$$$\n\n";
    ulamek3=ulamek2-ulamek1;
    std::cout<<ulamek3;
    std::cout<<"$$$$$$$$$$$$$$$$$$$$\n\n";
    std::cout<<ulamek3.to_decimal()<<std::endl;
    std::cout<<"$$$$$$$$$$$$$$$$$$$$\n\n";
    Ulamek ulamek4(3,9);
    std::cout <<ulamek4;
    std::cout<<"$$$$$$$$$$$$$$$$$$$$\n\n";
    ulamek4.skroc();
    std::cout<<ulamek4;
    std::cout<<"$$$$$$$$$$$$$$$$$$$$\n\n";

    return 0;
}