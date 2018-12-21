#include <iostream>
#include <fstream>
static std::string text;

std::string decompress(int& i);
bool isPositiveNumber(char c);
std::string repeat(std::string word, int n);

using namespace std;
int main()
{
    std::cout << "Hello World!\n";
    int i = 0;

    ifstream myfile;
    myfile.open ("input6.txt");

    if(myfile.is_open()){
        std::cout << "success opening the file\n";
        std::string line;
        while(std::getline(myfile, line)){
            text += line;
        }        
        std::cout << "size of input: " << text.size() << '\n';
        
        std::cout << "size of output: " << decompress(i).size() << std::endl;
    }
}

std::string decompress(int& i){
    char c;
    std::string result = "";

    while(i < text.size() && text[i] != ']'){
        c = text[i];
        if (isPositiveNumber(c))
        {
            int times = c - '0';
            i++;
            
            if(text[i] != '['){
                std::cout << "Error: repetition should be >= 1";
                return "";
            }

            result += repeat(decompress(i), times);
        }else
        {
            if(c != '[')
                result += c;
        }
        i++;
    }

    return result;
}

bool isPositiveNumber(char c){
    return (c >= '0' && c <= '9');
}

std::string repeat(std::string word, int n){
    std::string str = "";
    if (n < 1){
        std::cout << "Error: repetition should be >= 1";
        return "";
    }

    while (n > 0){
        str += word;
        n--;
    }

    return str;
}