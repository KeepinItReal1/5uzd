#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <iomanip>// std::setw


typedef std::multimap<std::string,int> multi_map;
typedef multi_map::iterator iterator;

bool is_file_exist(std::string fileName){
    std::ifstream infile(fileName);
    return infile.good();
}

// bool charFilter(char s){//turi buti in range 65-90 arba 97-122
//     if((s>=65 && s<=90) || (s>=97 && s<=122)){//jei geras false, kad nepakeistu
//         return false;
//     }
//     else return true;
// }

std::string filter(std::string& line){//panaikina visas ne lotyniskas raides bei pavercia char i lower
        std::replace_if(line.begin(), line.end(), [](char s){
         if((s>=65 && s<=90) || (s>=97 && s<=122)){//jei geras false, kad nepakeistu
        return false;
    }
    else return true;}, ' ');
        std::transform(line.begin(), line.end(), line.begin(), ::toupper);
        return line;
    }

void readFromFile(std::string fileName){
    if(is_file_exist(fileName)==1){
        std::cout<<"File opened succesfully!"<<std::endl;
        std::ifstream inf;
        inf.open(fileName);

        multi_map node;//dydi gausiu su node.size();

        std::string line;
        size_t lineNumber = 1;
        while (std::getline(inf, line)){
            filter(line);
            std::istringstream s(line);
            std::string zodis;
            while(s >> zodis){
                node.insert(std::pair<std::string,int>(zodis, lineNumber));
            }
            lineNumber++;
        }

    std::cout<<std::setw(15)<<std::left<<"Words: "<<std::setw(16)<<std::internal<<"| Reapeated: "<<std::right<<"| Lines:"<<std::endl;

    for(auto it = node.begin(); it != node.end(); it = node.upper_bound(it->first)){//it->first rodys i pirma std::pair nary a.k.a. std::string - pati zodi
        if(node.count(it->first)>1){

            std::cout<<std::setw(15)<<std::left<<it->first <<std::setw(16)<<std::internal<< node.count(it->first);
            std::pair <iterator,  iterator> bounds = node.equal_range(it->first);//http://www.cplusplus.com/reference/map/multimap/equal_range/

            for(iterator i=bounds.first;i!=bounds.second;++i){
                std::cout<<' '<< i->second;
            }
            std::cout<<'\n';
        }

    }
    }else{
        std::cout<<"File does not exist!"<<std::endl;
    }
}



int main(){
    readFromFile("text.txt");


    return 0;
}