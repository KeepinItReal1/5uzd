# 5uzd
```cpp
std::string filter(std::string& line){//panaikina visas ne lotyniskas raides bei pavercia char i lower
        std::replace_if(line.begin(), line.end(), [](char s){
         if((s>=65 && s<=90) || (s>=97 && s<=122)){//jei geras false, kad nepakeistu
        return false;
    }
    else return true;}, ' ');
        std::transform(line.begin(), line.end(), line.begin(), ::toupper);
        return line;
    }
    ```
