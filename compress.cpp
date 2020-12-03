#include <iostream>
#include <fstream>
static std::string text;

std::string decompress(int& i);
bool isPositiveNumber(const char& c);
std::string repeat(const std::string& word, const int& n);

using namespace std;
int main(int argc, char* argv[])
{
    if (argc < 2){
        cout << "Please, provide an input file." <<endl;
        return 0;
    }

    int i = 0;

    ifstream myfile;
    myfile.open (argv[1]);

    if(myfile.is_open()){
        std::cout << "success opening the file\n";
        std::string line;
        while(std::getline(myfile, line)){
            text += line;
        }        
        std::cout << "size of input: " << text.size() << '\n';
        std::string textOutput = decompress(i);
        std::cout << "size of output: " << textOutput.size() << std::endl;

        myfile.close();

        ofstream output;
        output.open("output.txt");
        output << textOutput;
        output.close();
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

bool isPositiveNumber(const char& c){
    return (c >= '0' && c <= '9');
}

std::string repeat(const std::string& word, const int& times){
    std::string str = "";
    int n = times;
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