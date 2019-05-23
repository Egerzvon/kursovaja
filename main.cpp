#include <iostream>
#include <string>
#include <fstream>
#include <vector>

const std::string SPECS[] = {"year","color","engine capacity","akpp//mkpp","engine power","fuel tank","fuel consumption","dimensions","heated steering wheel","abs","eds","navigation system","board computer","heated seats","roof rack","number of airbags"};



class automobile
{
public:
    std::vector<std::string> params;
    automobile(std::ifstream& file){this->read(file);}
    void read(std::ifstream& file)
    {
        std::string buf;
        for(auto&& specification : SPECS){
            std::getline(file,buf);
            params.push_back(buf);
        }
    }
    void print(){
        for(int i=0; i<params.size(); i++)
            std::cout << SPECS[i] << " : " << params[i] << std::endl;   
    }
    
};

class handler
{
public:
    std::string filename;  

    handler(std::string filename):filename(filename){};
    bool find_automobile(std::string model)
    {
        std::ifstream file(this->filename);
        bool found=false;
        std::string buf;
        while(std::getline(file,buf) && found==false)
        {
            if(model.compare(buf)==0)
            {
                found=true;
                std::cout << this->filename << ": found!" << std::endl;
                automobile founded(file);
                founded.print();
                return true;
            }
        }
        if(!found) return false;

    }     

};

class reciver
{
    private:
    std::vector<handler> v;
    public:
    reciver(handler begin){this->set_next(begin);}
    void set_next(handler next){v.push_back(next);}
    void find(std::string model)
    {
        for (auto it = v.begin(); it != v.end(); ++it) {
            if(it->find_automobile(model)) return;
            else std::cout<<it->filename<<" not found"<<std::endl;
        }
        std::cout << "Model does not exist" << std::endl;
        return;
    }
};


int main(int argc, char const *argv[])
{
    reciver autosalon(handler("salon"));
    autosalon.set_next(handler("dealer"));
    autosalon.set_next(handler("manufacture"));
    autosalon.find("creta");
    return 0;
}
