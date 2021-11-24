#include <iostream>
#include <string.h>

int main(){
    // size of wide char is doubled size of char
    wchar_t w = L'A';
    std::cout << "Wide character value : " << w << "\n";
    std::cout << "Wide character size : " << sizeof(w) << "\n";

    // char and wide_char are basically the same
    // wchar_t need to use std::wcout to pipe into out stream
    char c[] = "ABC";
    std::cout << c << "\n";
    wchar_t wc[] = L"ABC,DEFGB,OJKsdl";
    std::wcout << wc << "\n";
    std::cout << wc << "\n";
    std::wcout << L"The legnth of " << wc << L" is " << wcslen(wc) << "\n";

    //wcscpy: Wide-Character String COPY
    wchar_t wc_copy[wcslen(wc)];
    wcscpy(wc_copy, wc);
    std::wcout << L"The original wide character array is " << wc << L"\n The copied one is " << wc_copy << "\n";
    
    // Tokenize
    std::wcout << L"Start to tokenize a wide character array : " << wc << "\n";
    wchar_t* internal_state;
    wchar_t delim[] = L",";
    wchar_t* token = wcstok(wc, delim, &internal_state);
    while(token){
        std::wcout << token << "\n";
        token = wcstok(NULL, delim, &internal_state);
    }
    return 0;
}