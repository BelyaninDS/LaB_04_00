#include <iostream>
#include <cstdint>
#include "hex_print.h"
#include "bool_print.h"
using namespace std;



//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------


/*char bit_digit(uint8_t byte,uint8_t bit){
    if(byte & (0x1<<bit)){return '1';}
    return '0';
}


void print_in_binary(uint8_t byte){
    for(int i=7;i>0;i--)
        cout<<bit_digit(byte,i);
}


void print_in_binary(void* data,size_t size) {

    const uint8_t* bytes = as_bytes(data);
    for (int i = 0; i < size; i++) {
        print_in_binary(bytes[i]);
        if ((i + 1) % 4 == 0) { cout << '\n'; }
        else { cout << ' '; }
    }
}*/


//--|\  /|-----/\-----|---|\  |---------------------------------------------------------
//--| \/ |----/__\----|---| \ |---------------------------------------------------------
//--|    |---/    \---|---|  \|---------------------------------------------------------

int check_operation_input(char operation){
    if((operation == '&')||(operation == '|')||(operation == '^'))
        return 0;
    else
        cerr<<"\nError! Wrong operation";
        return 1;
}





int main(){

    uint16_t first_op,second_op,result;
    char operation;

    cin>>first_op>>operation>>second_op;

    if(check_operation_input(operation) == 1) return 0;

    switch(operation){
        case '&':
            result = first_op & second_op;
            break;
        case '|':
            result = first_op | second_op;
            break;
        case '^':
            result = first_op ^ second_op;
            break;
        default:{};
    }

    cout<<"\nHEX:\n";

    print_in_hex(&first_op,sizeof(first_op));
    cout<<" "<<operation<<" ";
    print_in_hex(&second_op,sizeof(second_op));
    cout<<" = ";
    print_in_hex(&result,sizeof(result));

    cout<<"\n\nBIN:\n";

    print_in_binary(&first_op,sizeof(first_op));
    cout<<" "<<operation<<" ";
    print_in_binary(&second_op,sizeof(second_op));
    cout<<" = ";
    print_in_binary(&result,sizeof(result));
    
    return 0;
}




