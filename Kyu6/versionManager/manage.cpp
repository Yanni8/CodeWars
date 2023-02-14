
#include <string>
#include <vector>
#include <iostream>

class VersionException
{
    public:
        VersionException(std::string msg){};
};
#include <string>
#include <vector>
#include <iostream>

class Version
{
public:
    unsigned int x, y, z;
    Version *clone() const { return new Version(*this); }
    
    Version(std::string preloadetVersion){
        int pos1 = preloadetVersion.find(".")+1, pos2 = preloadetVersion.find(".", pos1)+1;
        x = std::stoi(preloadetVersion.substr(0, pos1));
        y = std::stoi(preloadetVersion.substr(pos1,pos2));
        z = std::stoi(preloadetVersion.substr(pos2));
    }
    std::string versionNumber() const
    {
        return std::to_string(x) + "." + std::to_string(y) + "." + std::to_string(z);
    }
};

class VersionManager
{
public:
    VersionManager(std::string version = "0.0.1");
    VersionManager &major();
    VersionManager &minor();
    VersionManager &patch();
    VersionManager &rollback();
    std::string release() const;

private:
    Version currentVersion = Version("0.0.1");
    std::vector<Version *> *versionHistory = new std::vector<Version *>();
};

VersionManager::VersionManager(std::string version){
    if (version.empty())
    {
        return;
    }
    if (version.back() == '.')
    {
        version += "0";
    }
    
    version += ".0.0";
    try{    currentVersion = Version(version);}
    catch(std::exception e){throw VersionException("Error occured while parsing version!");}
}

VersionManager &VersionManager::major()
{
    (*versionHistory).push_back(currentVersion.clone());
    currentVersion.y = 0;
    currentVersion.z = 0;
    currentVersion.x++;
    return (*this);
}

VersionManager &VersionManager::minor()
{
    (*versionHistory).push_back(currentVersion.clone());
    currentVersion.z = 0;
    currentVersion.y++;
    return (*this);
}

VersionManager &VersionManager::patch()
{
    (*versionHistory).push_back(currentVersion.clone());
    currentVersion.z++;
    return (*this);
}

VersionManager &VersionManager::rollback()
{
    if ((*versionHistory).size() == 0)
    {
        throw VersionException("Cannot rollback!");
    }

    Version *lastVersion = (*versionHistory).back();
    (*versionHistory).pop_back();
    currentVersion = *lastVersion;
    return (*this);
}
std::string VersionManager::release() const
{
    return currentVersion.versionNumber();
}

/**
 * URL: https://www.codewars.com/kata/5bc7bb444be9774f100000c3
 */
int main(int argc, char *argv[])
{
    std::cout << VersionManager().major().rollback().release() << " Should be 0.0.1" << std::endl;
    std::cout << VersionManager().major().release() << " Should be 1.0.0" << std::endl;
    std::cout << VersionManager("1.2.3").major().major().release() << " Should be 3.0.0" << std::endl;
    

}