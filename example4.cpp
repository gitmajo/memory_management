#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Resource
{
    Resource(char* byte) : byte_(byte) {}
    virtual string name() const = 0;
    ~Resource() { delete byte_; }

protected:
    char* byte_ = nullptr;
};

struct ResourceA : Resource
{
    ResourceA(char* byte) : Resource(byte) {}
    string name() const override { return string("ResourceA ").append(byte_); }
};

struct ResourceB : Resource
{
    ResourceB(char* byte) : Resource(byte) {}
    string name() const override { return string("ResourceB ").append(byte_); }
};

struct ResourceFactory
{ 
    Resource* makeResourceA(char* byte) { return new ResourceA{byte}; }
    Resource* makeResourceB(char* byte) { return new ResourceB{byte}; }
};

int main()
{
    vector<Resource*> resources;
    ResourceFactory rf;
    resources.push_back(rf.makeResourceA(new char{0x01}));
    resources.push_back(rf.makeResourceB(new char{0x02}));
    for (const auto & res : resources)
    {
        cout << res->name() << endl;
    }
    auto firstName = resources[0]->name();
    resources.clear();
    cout << firstName << endl;

    return 0;
}

